#define EXTISM_IMPLEMENTATION
#define EXTISM_ENABLE_LOW_LEVEL_API
#include "extism-pdk.h"
#include <stdint.h>
#include <string.h>

int32_t EXTISM_EXPORTED_FUNCTION(httpget)
{
  const char *reqAsStr = "{\"url\": \"https://httpbin.org/anything\"}";

  ExtismPointer req = extism_alloc_string(reqAsStr, strlen(reqAsStr));
  ExtismPointer res = extism_http_request(req, 0);

  if (extism_http_status_code() != 200)
  {
    return -1;
  }

  extism_output_set(res, extism_length(res));
  return 0;
}
