package com.gix.change_c_pointer
fun main() {
    var app = App()

    val nativeThread = Thread { app.cMain() }
    nativeThread.start()

    println(app.greeting)

    println("Get address: " + app.address)
    println("Get address: " + app.address)

    app.doubleGrade(app.address)
    println("Turn off loop in native")
    app.turnOff(app.address);

    nativeThread.join()
}
