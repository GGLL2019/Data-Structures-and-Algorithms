# Data-Structures-and-Algorithms

关于如何使用git　（以Data-Structures-and-Algorithms 工程为例子）
以下操作只进行一次
(1)克隆工程　Data-Structures-and-Algorithms　到本地


以下操作可进行多次
(2)查看当前状态：git status
(3)查看当前分支：git branch;（一般都在master分支下进行开发）
   如果需要修改文件内容或者新建文件或者文件夹：
(4)修改内容；
(5)git status 查看状态；（应该是在master分支下，有些文件因为修改变成红色，待add）
　下面以修改README.md文件为例子
(6)git add README.md;
(7)git status查看状态，已经add的文件是绿色；如果需要撤回，使用git reset HEAD 全部撤回add
(8)git commit -m "add methods for using git";
(9)更新代码，避免冲突：git pull --rebase;
(9)创建并切换分支(假设切换到guoxueliang分支（最好以个人名字命名）):git checkout -b guoxueliang;
(10)git status查看状态,应该已经在guoxueliang分支，而且与刚刚commit的状态一致
(11)上传：git push origin guoxueliang -f;

此时已经完成了整个上传过程，上传后，可在github网页中看到新的提交，进入够创建新的pull request，可自行merge，或找他人帮忙；
(12)切换到master主分支，git checkout master;
(13)删除新建的分支：git branch -d guoxueliang;
(14)当代码已经成功合入后，本地更新代码：git pull --rebase;
