#define EXTISM_IMPLEMENTATION
#include "extism-pdk.h"
#include <stdint.h>
#include <string.h>

int32_t EXTISM_EXPORTED_FUNCTION(httpget)
{
  const char *reqAsStr = "{\"url\": \"https://httpbin.org/anything\"}";

  ExtismHandle req = extism_alloc_buf_from_sz(reqAsStr);
  ExtismHandle res = extism_http_request(req, 0);

  if (extism_http_status_code() != 200)
  {
    return -1;
  }

  extism_output_set_from_handle(res, 0, extism_length(res));
  return 0;
}
