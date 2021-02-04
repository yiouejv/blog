# 后台管理系统

## 后台配置

1. 登陆地址： /admin/

2. 创建后台管理员（超级用户）

   ```python
   python manage.py createsuperuser
   ```

## Models 的基本管理

1. 在应用中的`admin.py`中注册要管理的实体类

   ```
   admin.py作用：
   	注册要管理的Models类，只有注册之后才能管理
   注册Models
   	admin.site.register()
   ```

2. 类设置

   重写每个实体类中的`__str__()`方法，后台显示的将以`__str__()`的返回值为准

   为实体类中的属性们添加字段选项 verbose_name，用于修改显示的字段名

3. 通过Model类的内部类Meta定义其展现形式

   ```python
   class Author(models.Model):
       name = models.CharField(max_length=20)
   
       class Meta():
           1. db_table = ''  # 指定该实体类映射到表的名称，该属性设置完成后需要同步回数据库
           2. verbose_name = ''
           # 定义类在admin中显示的名字(单数)
           3. varbose_name_plural
           # 定义类在admin中显示的名字(复数)
           4. ordering
           # 指定数据在后台管理中的排序方式
           # 取值一个列表，指定排序列，默认升序，降序使用
   ```

## Models 的高级管理

1. 在admin.py中创建高级管理类并注册

   ```python
   # 创建 EntryAdmin类，继承自admin.ModelAdmin
   class AuthorAdmin(admin.ModelAdmin):
   	pass
   # 注册高级管理类
   admin.site.register(Entry, EntryAdmin)
   # ex:
   admin.site.register(Author, AuthorAdmin)
   ```

2. 允许在EntryAdmin中增加的属性

   ```python
   # list_display
      作用
          定义在列表也上显示的字段们
      取值：
          由模型类中对象的属性名组成的元组或列表
   # list_display_links
       作用
           定义在列表页上也能够链接到详情页的字段们
   # list_editable
       作用
           定义在列表页上就能够修改的字段们
       取值
           只能出现在list_display中，不能出现在list_display_links中
   # search_fields
       作用
           在列表页的偏上添加一个搜索栏，、
           定义搜索栏中允许搜索的字段值们
   # list_filter
       作用
           在列表页的右侧增加过滤器来实现快速筛选
   # date_hierarchy
       作用
           在列表页的顶部会增加一个时间选择器，取值属性必须是DateField 或 DateTimeField的列
   # fields
       作用
           在详情页面中，指定要显示那些字段并按照什么顺序显示
   # fieldsets
       作用
           在详情页中对字段们进行分组显示
       注意
           fieldssets 与 fields 不能共存
       取值
           fieldssets = [
               # 分组1
               ('分组名称', {
                   'fields': ('属性1', '属性2'),
                   'classes': ('collapse',)  # collapse 折叠
               }),
   
               # 分组2
           ]
   ```

   