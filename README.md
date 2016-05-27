# Back_up-Folder
*Software Enginering in SUSY, Weihong Lin*

A simple program helps back-up the folder，change it into zip，and place it in specific place.

---

###1.Backgroud

Sometimes I find it inconvenient to back-up some important folders by using the zip software and moving the back-up document to the specific place. Hence I consider that if I can design a program that can help me back-up my important folder by a simple step, just running the program, and the task will complete it by computer automatically, it will save me a lot of time, help my work more efficient.


*Impletement*: C++
*Platform*: OS X
*Content*: back_up.cpp, 1.txt(used for testing)

###2.Requirement
The program is based on the boost library and if you don't possess it, you can run this command `brew install boost` in your terminal.
Also, you can refer to some tutorials, here I recommand my blog written in Chinese to you, and the passage also provides the course of install boost and the setting in Xcode.
The Link: [ 实践篇：Install Homebrew and Boost Library 以及 Xcode配置Boost库](http://blog.csdn.net/linwh8/article/details/51445257). I hope it can help you!

According to the place you install the boost, you should link it in your g++ command:
```
/*
default installation directory：
            Library: /usr/loacl/lib  
            Header: /usr/local/include
*/
g++ main.cpp -L/usr/local/lib -I/usr/local/include -lboost_filesystem -lboost_system
```

###3.Function
Since its the original version, it may be a lot of bugs and enable impletementing single function: Back-up the folder and move it to the specific place.

For convenience, you can save your source path, target path as well as the name of back_up in the txt such as 1.txt in the same directory of a.out, and use `cat 1.txt| ./a.out` to run it.

More details are written as comment in back_up.cpp.

###4.Update
1.2016/5/27   Publish the original version.
