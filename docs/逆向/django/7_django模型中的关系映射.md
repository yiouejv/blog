# django模型中的关系映射

## 一对一映射 

- 语法：在关联的两个类中的任何一个类都可以增加对另一个类的引用

  **属性 = modles.OneToOneField(Entry)**

  ```python
  # 在Wife实体类中增加对Author实体类的一对一引用
  
  class Author(models.Model):
  	...  ...
  
  class Wife(models.Model):
  	... ...
      # 增加一对一的引用
      author = modles.OneToOneField(Author)
  ```

  - 数据库中会生成一个外键(author_id)列在wife表中, 会引用在author表的主键
  - 在Author中，会增加一个隐式属性，来表示author所对应的wife（其实反向引用属性）

- 查询

  - 正向查询： 通过wife 找 author 

    ```python
    # 特点： 通过自定义的关联属性去查找对应的实体
    wife = Wife.objects.get(id=1)
    author = wife.author
    ```

  - 反向查询：通过author 找 wife

    ```python
    # 特点： 通过反向引用属性去查找对应的实体
    author = Author.objects.get(id=1)
    wife = author.wife
    ```

## 一对多映射 

- 语法

  在'多'表中增加对'一'表的外键引用（数据库中表现）

  在'多'实体中增加对'一'实体的引用（django模型中操作）

  **属性 = models.ForeignKey(Entry)**

  ```python
  # 一个出版社对应多本书
  # Book   Publisher
  #  多       一
  class Book(models.Model):
      ... ...
      publisher = models.ForeignKey(Publisher)
  ```

  - Book 表中增加一个外键列 publisher_id, 引用自Publisher 表中的主键
  - Publisher 中会由一个隐式属性 book_set, 用来表示该publisher对应的所有的Book对象的查询

## 多对多映射 

- 语法

  在关联的两个类的任意一个类中，增加

  **属性 = models.ManyToManyField(Entry)**

  ```python
  # Author   Book 可以的是多对多关联关系
  # 一个author 可以出版多本book
  # 一本book 可以由多位 author 联合编写
  class Author(models.Model):
      ... ...
  
  class Book(models.Model):
      ... ...
      authors = models.ManyToManyField(Author)
  ```

  - Book 表中增加一个外键列 publisher_id, 引用自Publisher 表中的主键
  - Publisher 中会由一个隐式属性 book_set, 用来表示该publisher对应的所有的Book对象的查询

- 查询

  通过 Book 查询 authors:

  ```python
  authors = book.authors.all() 
  ```

  反向查询：

  ```python
  books = author.book_set.all()
  ```