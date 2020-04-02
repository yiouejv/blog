
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

### git help  
1. git help < verb >  
- git < verb > --help  
- man git-< verb >

### git init   
该命令将创建一个名为 .git 的子目录，这个子目录含有你初始化的 Git 仓库中所有的必须文件，这些文件是 Git 仓库的骨干。 但是，在这个时候，我们仅仅是做了一个初始化的操作，你的项目里的文件还没有被跟踪。

### git clone  
1. 如果你想获得一份已经存在了的 Git 仓库的拷贝，比如说，你想为某个开源项目贡献自己的一份力，这时就要用到 git clone 命令。  
- 如果你对其它的 VCS 系统（比如说 Subversion）很熟悉，请留心一下你所使用的命令是"clone"而不是"checkout"。 这是 Git 区别于其它版本控制系统的一个重要特性，Git 克隆的是该 Git 仓库服务器上的几乎所有数据，而不是仅仅复制完成你的工作所需要文件。  
- 当你执行 git clone 命令的时候，默认配置下远程 Git 仓库中的每一个文件的每一个版本都将被拉取下来。 事实上，如果你的服务器的磁盘坏掉了，你通常可以使用任何一个克隆下来的用户端来重建服务器上的仓库 （虽然可能会丢失某些服务器端的钩子（hook）设置，但是所有版本的数据仍在.  
- 克隆仓库的命令是  <span style="color: red;">git clone < url ></span>
- 克隆远程仓库的时候，自定义本地仓库的名字 <span style="color: red;">git clone < url > newname</span>
	
### git status  
1. 可以用 git status 命令查看哪些文件处于什么状态。
2. git status --short 得到一种格式更为紧凑的输出

### git add
1. 跟踪一个未跟踪的文件。
2. 将跟踪的文件放入暂存区
3. 合并时把有冲突的文件标记为已解决状态

### .gitignore
一般我们总会有些文件无需纳入 Git 的管理，也不希望它们总出现在未跟踪文件列表。 通常都是些自动生成的文件，比如日志文件，或者编译过程中创建的临时文件等。 在这种情况下，我们可以创建一个名为 .gitignore 的文件，列出要忽略的文件的模式。 

```
*.[oa]
*~
```  
第一行告诉 Git 忽略所有以 .o 或 .a 结尾的文件。  
第二行告诉 Git 忽略所有名字以波浪符（~）结尾的文件，许多文本编辑软件（比如 Emacs）都用这样的文件名保存副本。
***文件 .gitignore 的格式规范如下：***  
- 所有空行或者以 # 开头的行都会被 Git 忽略。  
- 可以使用标准的 glob 模式匹配，它会递归地应用在整个工作区中。  
- 匹配模式可以以（/）开头防止递归。  
- 匹配模式可以以（/）结尾指定目录。  
- 要忽略指定模式以外的文件或目录，可以在模式前加上叹号（!）取反。

### git diff
1. 不加参数直接输入 git diff : 尚未暂存的文件更新了哪些部分   
2. git diff --staged : 已暂存文件与最后一次提交的文件差异  
3. git diff --cached : --staged 和 --cached 是同义词

### git commit
1. git commit -m "message": 提交代码
2. 请记住，提交时记录的是放在暂存区域的快照。 任何还未暂存文件的仍然保持已修改状态，可以在下次提交时纳入版本管理。 每一次运行提交操作，都是对你项目作一次快照，以后可以回到这个状态，或者进行比较。  
3. git commit -m -a "message": 尽管使用暂存区域的方式可以精心准备要提交的细节，但有时候这么做略显繁琐。 Git 提供了一个跳过使用暂存区域的方式， 只要在提交的时候，给 git commit 加上 -a 选项，Git 就会自动把所有已经跟踪过的文件暂存起来一并提交。  

### git rm
1. git rm file: 从已跟踪文件清单中移除（确切地说，是从暂存区域移除）, 并连带从工作目录中删除指定的文件
2. git rm -f file: 如果要删除之前修改过或已经放到暂存区的文件，则必须使用强制删除选项 -f（译注：即 force 的首字母）  
3. git rm --cached file: 让文件保留在磁盘，但是并不想让 Git 继续跟踪。  

### git mv
1. git mv README.md README 相当于  
```
mv README.md README
git rm README.md
git add README
```
不像其它的 VCS 系统，Git 并不显式跟踪文件移动操作。 如果在 Git 中重命名了某个文件，仓库中存储的元数据并不会体现出这是一次改名操作。 不过 Git 非常聪明，它会推断出究竟发生了什么。


