#include "key.h"

char key_to_char(mmi_key_t key)
{
  if (key >= KEY_A && key <= KEY_Z)
  {
    return key - KEY_A + 'A';
  }
  else if (key >= KEY_0 && key <= KEY_9)
  {
    return key - KEY_0 + '0';
  }
  else if (key == KEY_SPACE)
  {
    return ' ';
  }
  else
  {
    return 0;
  }
}

bool key_is_printable(mmi_key_t key)
{
  // ASSUMPTION: A-Z[space]0-9 keys are contiguous in key enum
  return key >= KEY_A && key <= KEY_9;
}
