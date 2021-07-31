# git笔记

### 1、简单的代码提交流程

------

​	1、git status 查看工作区代码相对于暂存区的差别  
​	2、git add . 将当前目录下修改的所有代码从工作区添加到暂存区 . 代表当前目录  
​	3、git commit -m ‘注释’ 将缓存区内容添加到本地仓库  
​	4、git pull origin master先将远程仓库master中的信息同步到本地仓库master中  
​	5、git push origin master 将本地版本库推送到远程服务器，origin是远程主机，master表示是远程服务器上的master分支和本地分支重名的简写，分支名是可以修改的  

------

### 2、拷贝代码：

​    git clone http://git.jintencent.com/jv-svr/jvms_proj_release.git  
​    git clone https://github.com/niyungao/hello-world.git   
​    git clone git@github.com:niyungao/hello-world.git    

------

### 3、查看分支：

​    查看本地分支：  

​        git branch  

​    查看远程分支：  

​        git branch -r  

​    查看所有分支：  

​        git fetch origin  

​        git branch -a  

-----

### 4、切换分支：

​    切换远程分支(并在本地起名)：  

​        git checkout -b myRelease origin/Release  

​        作用是checkout远程的Release分支，在本地起名为myRelease分支，并切换到本地的myRelase分支  

​    切换远程分支：  

​        git checkout -b origin/Release  

​    回到master：  

​        git checkout master  

-----

### 5、拉取指定分支代码到当前分支：

​    git pull origin master  

​    注意：  

​        1、每次使用该命令前，需要保证本地工作区是没有任何修改代码的，也就是说需要将本地工作区编辑过的文件添加到暂存区（git add .），或提交到本地仓库中(git commit)，才可以使用该命令拉取指定分支的代码合并到当前分支中。  

​        2、每次在操作完git commit命令后，必须拉取一下master分支代码，保持本地正在开发功能逻辑的代码分支代码是最新的，避免后续在提交时冲突过多或覆盖掉其他人的代码的问题出现。  

----

### 6、git撤销提交(commit)  

​    git reset  

​        当git reset 后面的commitId为当前提交的commitId时，即HEAD(可缺省)。那么：  

​         参数说明：  

​                --hard HEAD 修改暂存区、工作区里面的内容为当前快照里的内容。（这个很危险，曾经踩过坑，电脑的文件丢失了很多，也是导致我决心好好学一学git的原因，慎用）  

​                --mixed HEAD 修改暂存区里面的内容为当前快照里的内容，是git reset默认的参数，因此可缺省。  

​                --soft HEAD 本地仓库、暂存区、工作区都不改变  

​            具体说明：  

​                --mixed   

​                    意思是：不删除工作空间改动代码，撤销commit，并且撤销git add . 操作  

​                    这个为默认参数,git reset --mixed HEAD^ 和 git reset HEAD^ 效果是一样的。  

​                --soft   

​                    不删除工作空间改动代码，撤销commit，不撤销git add .   

​                --hard  

​                    删除工作空间改动代码，撤销commit，撤销git add .   

​                    注意完成这个操作后，就恢复到了上一次的commit状态。  

----

### 7、撤消工作区的修改：

​    git checkout -- filename 

​    使用暂存区或版本库中的文件覆盖工作区的文件，就是让这个文件回到最近一次git add或git commit时的状态。   

​    1、如果文件修改后还没有被放到暂存区，只需要执行git checkout -- filename可以丢弃工作区的修改，恢复到和远程版本库一模一样的状态。       

​    2、如果文件修改后已经通过git add命令添加到了暂存区，执行git checkout -- filename命令将会把文件恢复到与暂存区一模一样的状态。     

​    3、如果文件修改后已经通过git commit命令提交到了版本库，执行git checkout -- filename将会把文件恢复到与本地版本库一模一样的状态。       

​    注意：git checkout -- . 命令会将工作区的所有文件的修改都撤消。     

----

### 8、清空缓存区：

​    撤回暂存区所有文件：git reset HEAD   

​    撤回暂存区指定的文件：git reset HEAD filename   

​    删除缓存区指定的文件：git rm --cache filename   

----

### 9、撤消工作区所有已暂存未提交的修改

​    git reset HEAD   

​    git checkout -- .    

----

### 10、放弃所有的本地改动与提交，到服务器上获取最新的版本并将本地主分支指向到它：

​    git fetch origin   

​    git reset --hard origin/master   

----

### 11、删除本地文件：

​    rm -rf A/b   

----

### 12、git 本地tag和远程tag对应不上 vscode里pull不下代码:

​    报错“! [rejected]  dataSource0424 -> dataSource0424 (would clobber existing tag)”   

​        1、查看远程tags: git ls-remote -t   

​        2、查看本地tags: git tag -l   

​        3、删除本地与远程不一致的tag: git tag -d tag名字  

​        4、重新拉取远程tag: git fetch origin --prune-tags  

​        5、git pull 拉取代码  

----

### 13、vscode安装vsix文件:

​    code --install-extension xxxxx.vsix   