# Slibrary
基于C的图书馆系统，包含图书管理，读者管理和本地管理。
## <br/> 1.运行环境？
提交的版本是基于devc++建立的项目，想来能做这种作业应付的，你应该也会在windows上交作业。之前的版本一直是基于unix系统的，为了提交作业改到windows平台。
## <br/> 2.项目组成？
对book操作的文件夹，即对图书进行一系列管理。reader中是对读者进行操作，主函数是调用两者。
## <br/> 3.数据结构？
book和reader采用双链表，每次从本地txt读取数据加载，因为链表便于修改，修改完成后保存至本地txt。订单order部分则是直接存储为txt。
## <br/> 4.其它
### <br/>1.乱七八糟的头文件
写到一半规定不能超过100行，所以强行拆了book.c，但是后来又取消了规定，所以reader.c是完整的。你也可以把book文件夹中函数合并。
### <br/>2.COPY问题
欢迎随便拿去应付作业，我们都是被逼无奈，我懂。(湖北的童鞋可以联系我，防止同校撞车)
