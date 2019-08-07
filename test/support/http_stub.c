#include "http_stub.h"

static int                m_calls_num;
static mg_event_handler_t m_handler;
static void             * m_ud;
static char               m_url[1024];
static char               m_req_headers[1024];
static char               m_req_body[1024];

struct mg_connection *http_stub_set(struct mg_mgr* mgr,
                              mg_event_handler_t event_handler, void* user_data,
                              const char* url, const char* extra_headers,
                              const char* post_data, int cmock_num_calls)
{
  if(url != NULL) {
    strcpy(m_url, url);
  } else {
    m_url[0] = '\0';
  }
  if(extra_headers != NULL){
    strcpy(m_req_headers, extra_headers);
  } else {
    m_req_headers[0] = '\0';
  }
  if(post_data != NULL) {
    strcpy(m_req_body, post_data);
  } else {
    m_req_body[0] = '\0';
  }

  m_handler     = event_handler;
  m_ud          = user_data;
  m_calls_num  += 1;

  return NULL;
}

void http_stub_clear(void)
{
  m_url[0]          = '\0';
  m_req_headers[0]  = '\0';
  m_req_body[0]     = '\0';
  m_calls_num       = 0;
  m_handler         = NULL;
  m_ud              = NULL;
}

bool http_stub_response(int connect_code, int http_status, const char *body)
{
  struct mg_str body_str = mg_mk_str(body);
  struct http_message hm = { .body = body_str, .resp_code = http_status };

  if(m_handler != NULL) {
    m_handler(NULL, MG_EV_CONNECT, (void*)&connect_code, m_ud);

    if(connect_code >= 0) {
      m_handler(NULL, MG_EV_HTTP_REPLY, (void*)&hm, m_ud);
    }
    return true;
  }

  return false;
}

const char* http_stub_req_url(void) {
  return (const char *) m_url;
}

const char* http_stub_req_headers(void)
{
  if(m_req_headers[0] == 0) {
    return NULL;
  }

  return (const char *) m_req_headers;
}

const char* http_stub_req_body(void)
{
  if(m_req_body[0] == 0) {
    return NULL;
  }

  return (const char *) m_req_body;
}

int http_stub_calls_num(void) {
  return m_calls_num;
}
