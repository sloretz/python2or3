// Copyright 2019 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdlib.h>
#include <unistd.h>


int main(int argc, char ** argv)
{
  // Copy argv to a null-terminated array
  char ** null_terminated_argv = malloc((argc + 1) * sizeof(char *));
  if (!null_terminated_argv) {
    // Failed to malloc
    return 1;
  }
  for (int i = 0; i < argc; ++i) {
    null_terminated_argv[i] = argv[i];
  }
  null_terminated_argv[argc] = NULL;

  // Try python2 or python3 first
  execvp("python" PYTHON_VERSION, null_terminated_argv);

  // That didn't work, use the full path to the python interpreter found when this was built
  execv(PYTHON_PATH, null_terminated_argv);

  // Should never be executed
  free(null_terminated_argv);
  return 2;
}
