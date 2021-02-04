## yiouejv 的博客记录

> Stay Hungry Stay Foolish.


### 本电子书制作和写作方式
使用 mkdocs 和 markdown, mkdocs-material 构建。   
markdown 语法参考：<http://xianbai.me/learn-md/article/about/readme.html>  
mkdocs-material 官网: <https://squidfunk.github.io/mkdocs-material/>  

安装依赖：
```sh
# 方式1：
pip install mkdocs    # 制作电子书, http://markdown-docs-zh.readthedocs.io/zh_CN/latest/
# https://stackoverflow.com/questions/27882261/mkdocs-and-mathjax/31874157
pip install https://github.com/mitya57/python-markdown-math/archive/master.zip
```

编写并查看：
```sh
mkdocs serve     # 修改自动更新，浏览器打开 http://localhost:8000 访问
# 数学公式参考 https://www.zybuluo.com/codeep/note/163962
mkdocs gh-deploy    # 部署到自己的 github pages, 如果是 readthedocs 会自动触发构建
```

### 访问

[http://yiouejv.com](http://yiouejv.com)
