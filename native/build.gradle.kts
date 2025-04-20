task <Exec>("compileNative"){
    commandLine("sh","-c","mkdir -p build && cd build && cmake .. && cmake --build .")
 }
 
 task<Exec>("cleanNative"){
    commandLine("sh","-c","mkdir -p build && cd build && make clean")
 
 }