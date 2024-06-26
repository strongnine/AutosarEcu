> 以下是有关于 C 语言编程规范的内容，一些细节可以不严格按照以下所述来做，具体细节可以根据当前正在参与的项目进行微调。

总体原则保证易读、易维护、安全、可靠、可测试、高效、可移植。

## 命名规则

| 命名风格               | 命名方式                                                     | 类型                                                         |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 驼峰命名法             | 又名小驼峰。首字母小写，每个逻辑断点都用大写字母标记         | 变量、全局变量、结构体变量、联合体变量、函数参数、宏参数、结构体中成员 |
| 帕斯卡（Pascal）命名法 | 又名大驼峰。与驼峰命名法类似，只是首字母大写。               | 结构体类型、枚举类型、联合体类型                             |
| 全大写 + 下划线        | 全部大写，使用下划线进行分割                                 | 宏、常量、枚举值、goto 标签                                  |
| 匈牙利命名法           | 变量名前加上相应的小写字母符号作为前缀，标识出变量的作用域、类型 | 全局变量（`g_`）                                             |


一般性规则：

- 不使用制表符，使用空格替代；
- 每个缩进级别使用 4 个空格；
- 在关键字和左括号之间使用一个空格；
- 在函数名和左括号之间不要使用空格；
- 不在变量、函数、宏、类型重使用 `_` 或前缀。（这是 C 语言本身保留的）
- 对于严格的模块私有函数，使用 `prv_name` 前缀；
- 宏定义中的变量使用全部大写，再加 `_` 做单词间的分割；

例如：

```c
int s;
int a, b;
s = sum(a, b);
```



---

参考：

[1] [gitte - C语言编程规范 by liuhui. ](https://gitee.com/openharmony/docs/blob/master/zh-cn/contribute/OpenHarmony-c-coding-style-guide.md) 
