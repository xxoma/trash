#ifndef CS_MONGOOSE_SRC_COMMON_H_
#define CS_MONGOOSE_SRC_COMMON_H_

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include "common/mg_str.h"

#define MG_ENABLE_CALLBACK_USERDATA 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct mg_mgr {
  struct mg_connection *active_connections;
  void *user_data; /* User data */
  int num_ifaces;
  int num_calls;
  struct mg_iface **ifaces; /* network interfaces */
  const char *nameserver;   /* DNS server to use */
};
struct mg_connection {
  void *user_data; /* User data */
};

#ifndef MG_MAX_HTTP_HEADERS
#define MG_MAX_HTTP_HEADERS 20
#endif

/* Events. Meaning of event parameter (evp) is given in the comment. */
#define MG_EV_POLL 0    /* Sent to each connection on each mg_mgr_poll() call */
#define MG_EV_ACCEPT 1  /* New connection accepted. union socket_address * */
#define MG_EV_CONNECT 2 /* connect() succeeded or failed. int *  */
#define MG_EV_RECV 3    /* Data has been received. int *num_bytes */
#define MG_EV_SEND 4    /* Data has been written to a socket. int *num_bytes */
#define MG_EV_CLOSE 5   /* Connection is closed. NULL */
#define MG_EV_TIMER 6   /* now >= conn->ev_timer_time. double * */

/* HTTP message */
struct http_message {
  struct mg_str message; /* Whole message: request line + headers + body */
  struct mg_str body;    /* Message body. 0-length for requests with no body */

  /* HTTP Request line (or HTTP response line) */
  struct mg_str method; /* "GET" */
  struct mg_str uri;    /* "/my_file.html" */
  struct mg_str proto;  /* "HTTP/1.1" -- for both request and response */

  /* For responses, code and response status message are set */
  int resp_code;
  struct mg_str resp_status_msg;

  /*
   * Query-string part of the URI. For example, for HTTP request
   *    GET /foo/bar?param1=val1&param2=val2
   *    |    uri    |     query_string     |
   *
   * Note that question mark character doesn't belong neither to the uri,
   * nor to the query_string
   */
  struct mg_str query_string;

  /* Headers */
  struct mg_str header_names[MG_MAX_HTTP_HEADERS];
  struct mg_str header_values[MG_MAX_HTTP_HEADERS];
};

#define MG_EV_HTTP_REQUEST 100 /* struct http_message * */
#define MG_EV_HTTP_REPLY 101   /* struct http_message * */
#define MG_EV_HTTP_CHUNK 102   /* struct http_message * */
#define MG_EV_SSI_CALL 105     /* char * */
#define MG_EV_SSI_CALL_CTX 106 /* struct mg_ssi_call_ctx * */

#if MG_ENABLE_CALLBACK_USERDATA
#define MG_UD_ARG(ud) , ud
#define MG_CB(cb, ud) cb, ud
#else
#define MG_UD_ARG(ud)
#define MG_CB(cb, ud) cb
#endif


/*
 * Callback function (event handler) prototype. Must be defined by the user.
 * Mongoose calls the event handler, passing the events defined below.
 */
typedef void (*mg_event_handler_t)(struct mg_connection *nc, int ev,
                                   void *ev_data MG_UD_ARG(void *user_data));

struct mg_connection *mg_connect_http(
    struct mg_mgr *mgr,
    MG_CB(mg_event_handler_t event_handler, void *user_data), const char *url,
    const char *extra_headers, const char *post_data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
