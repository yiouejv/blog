
## 阅读git官网的Book, 顺手记录一下，方便查阅   
<https://git-scm.com/book/en/v2>  

## git 命令记录   
### git config  
1. /etc/gitconfig 文件: 包含系统上每一个用户及他们仓库的通用配置。 如果在执行 git config 时带上 --system 选项，那么它就会读写该文件中的配置变量。 （由于它是系统配置文件，因此你需要管理员或超级用户权限来修改它。）

- ~/.gitconfig 或 ~/.config/git/config 文件：只针对当前用户。 你可以传递 --global 选项让 Git 读写此文件，这会对你系统上 所有 的仓库生效。

- 当前使用仓库的 Git 目录中的 config 文件（即 .git/config）：针对该仓库。 你可以传递 --local 选项让 Git 强制读写此文件，虽然默认情况下用的就是它。。 （当然，你需要进入某个 Git 仓库中才能让该选项生效。）

- 配置用户：  
    - git config --global user.name "username"  
    - git config --global user.eamil "email"  
    - 当你想针对特定项目使用不同的用户名称与邮件地址时，可以在那个项目目录下运行没有 --global 选项的命令来配置。(--local 相当于上述的local)  

- 配置编辑器  
    - git config --global core.editor.vim  
    - 当 Git 需要你输入信息时会调用它。 如果未配置，Git 会使用操作系统默认的文本编辑器。  

- 查看配置信息  
    - <span style="color: red;">查看当前仓库的配置: </span>git config --list  
    - git config < key >  
