#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef void(* _function)();

int main(int argc, char* argv[]){
  if(argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
    printf("[i] usage: rundll.exe [DLL] [DLL_EXPORTED_FUNCTION]");
    return 0;
  }

  HMODULE hModule = LoadLibraryA((LPCSTR)argv[1]);

  if(!hModule){
    printf("[-] Can't load dll");
    return -1;
  }
 
  if(argc < 3){
    FreeLibrary(hModule);
    return -1;
  }

  void *FunctionAddress = GetProcAddress(hModule, (LPCSTR)argv[2]);

  if(!FunctionAddress){
    printf("[-] Didn't find %s in %s", argv[2], argv[1]);
    return -1;
  }

  _function function = (_function)FunctionAddress;

  function();

  FreeLibrary(hModule);
  return 0;
}
