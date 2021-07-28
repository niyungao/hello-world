# hello-world

拷贝代码：
git clone http://git.jintencent.com/jv-svr/jvms_proj_release.git

查看本地分支：
git branch

查看远程分支：
git branch -r

查看所有分支：
git fetch origin
git branch -a

切换远程分支(并在本地起名)：
git checkout -b myRelease origin/Release
作用是checkout远程的Release分支，在本地起名为myRelease分支，并切换到本地的myRelase分支

切换远程分支：
git checkout -b origin/Release

回到master：
git checkout master

拉取代码：
git pull origin master

回退版本：
git status 
git log
git reset --hard a60b0ad6a70df029034d552bc2fba447fc94d915

删除本地文件：
rm -rf TradeMiddlePlatform/UserAssetBizSvr

git checkout TradeMiddlePlatform/CMakeLists.txt

简单的代码提交流程
1、git status 查看工作区代码相对于暂存区的差别
2、git add . 将当前目录下修改的所有代码从工作区添加到暂存区 . 代表当前目录
3、git commit -m ‘注释’ 将缓存区内容添加到本地仓库
4、git pull origin master先将远程仓库master中的信息同步到本地仓库master中
5、git push origin master 将本地版本库推送到远程服务器，
	origin是远程主机，master表示是远程服务器上的master分支和本地分支重名的简写，分支名是可以修改的

git 本地tag和远程tag对应不上 vscode里pull不下代码:
报错“! [rejected]          dataSource0424 -> dataSource0424  (would clobber existing tag)”
1、查看远程tags	git ls-remote -t
2、查看本地tags	git tag -l
3、删除本地与远程不一致的tag git tag -d tag名字
4、重新拉取远程tag git fetch origin --prune-tags
5、git pull 拉取代码

vscode安装vsix文件:
code --install-extension xxxxx.vsix
