#ifndef _HTTP_STUB_H
#define _HTTP_STUB_H

#include <stdbool.h>
#include "unity.h"
#include "mongoose.h"
#include "mgos_mongoose.h"

struct mg_connection *http_stub_set(struct mg_mgr* mgr,
                              mg_event_handler_t event_handler, void* user_data,
                              const char* url, const char* extra_headers,
                              const char* post_data, int cmock_num_calls);
void                  http_stub_clear(void);
bool                  http_stub_response(int connect_code, int status, const char *body);
const char*           http_stub_req_url(void);
const char*           http_stub_req_headers(void);
const char*           http_stub_req_body(void);
int                   http_stub_calls_num(void);

#ifndef TEST_ASSERT_REQUEST
#define TEST_ASSERT_REQUEST(calls_num, url, headers, body)                    \
  do {                                                                        \
    TEST_ASSERT_EQUAL_MESSAGE(calls_num, http_stub_calls_num(),               \
                              "Unexpected calls number");                     \
    TEST_ASSERT_EQUAL_STRING_MESSAGE(url, http_stub_req_url(),                \
                              "Unexpected URL");                              \
    TEST_ASSERT_EQUAL_STRING_MESSAGE(headers, http_stub_req_headers(),        \
                              "Unexpected headers");                          \
    TEST_ASSERT_EQUAL_STRING_MESSAGE(body, http_stub_req_body(),              \
                              "Unexpected body");                             \
  } while (0)
#endif // TEST_ASSERT_REQUEST


#endif // _HTTP_STUB_H