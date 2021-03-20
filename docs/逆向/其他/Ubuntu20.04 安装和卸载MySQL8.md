


### 安装MySQL8

1. 安装mysql-server 

    `sudo apt install mysql-server`

2. 初始化配置信息 

    `sudo mysql_secure_installation`

    - VALIDATE PASSWORD COMPONENT.....（使用密码强度校验组件） 输入： n
    - New Password:（设置新密码,并重复一遍)
    - Remove anonymous users (删除匿名用户) n
    - Disallow root login remotely(拒绝远程root账号登录） n
    - Remove test database and access to it(移除test数据库） n
    - Reload privilege tables now (现在就重新载入权限表） y

3. 登入到数据库并配置远程访问

### MySQL8 卸载

1. 查看MySQL依赖 ： 

    `dpkg --list|grep mysql`

2. 卸载： 

    `sudo apt-get remove mysql-common`

3. 卸载： 

    `sudo apt-get autoremove --purge mysql-server-8.0`

    (这里版本对应即可)

4. 清除残留数据: 

    `dpkg -l|grep ^rc|awk '{print$2}'|sudo xargs dpkg -P`

5. 再次查看MySQL的剩余依赖项: 

    `dpkg --list|grep mysql`

    (这里一般就没有输出了，如果有执行下一步)

6. 继续删除剩余依赖项，如：

    `sudo apt-get autoremove --purge mysql-apt-config`

第6部执行完了就彻底删除了









