/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkDirectory.h"
#include "itkTestingMacros.h"

int
itkDirectoryTest(int argc, char * argv[])
{
  const itk::Directory::Pointer directory = itk::Directory::New();

  if (argc < 2)
  {
    std::cerr << "Usage: " << itkNameOfTestExecutableMacro(argv) << " directory" << std::endl;
    return EXIT_FAILURE;
  }

  if (directory->Load("qwerty"))
  {
    std::cerr << "directory->Load(\"qwerty\")"
              << " should have failed." << std::endl;
    return EXIT_FAILURE;
  }
  directory->Load(argv[1]);
  directory->Print(std::cout);

  // Test GetFile with a success and failure
  if (directory->GetNumberOfFiles() > 0)
  {
    std::cout << "File 0 is " << directory->GetFile(0) << std::endl;
  }

  return EXIT_SUCCESS;
}
