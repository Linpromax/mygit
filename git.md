# Git笔记

**为什么Git比其他版本控制系统设计得优秀，因为Git跟踪并管理的是修改，而非文件。**



## 创建版本库

- 第一步， 创建一个版本库非常简单，首先，选择一个合适的地方，创建一个空目录： 

- ```
  $ cd ../g/Git  //通过命令行cd指定到你想要的目录下
  $ mkdir learngit
  $ cd learngit
  $ pwd
  /Users/michael/learngit
  ```
  
- `pwd`命令用于显示当前目录 。

- **查看本地仓库与远程仓库的关联详情**

```
  $ git remote -v
```

  > 删除与远程仓库的关联就比较简单了，直接输入以下命令：
  > $ git remote rm origin

## 初始化版本库

-  第二步，通过`git init`命令把**这个目录变成Git可以管理的仓库**： 

  ```
  $ git init
  Initialized empty Git repository in /Users/michael/learngit/.git/
  ```

  添加文件到Git仓库，分两步：

  1. 使用命令`git add `，注意，**可反复多次使用**，添加多个文件；
  2. 使用命令`git commit -m `，完成。

- 要随时掌握工作区的**状态**，使用`git status`命令。
- 如果`git status`告诉你有文件被修改过，用`git diff`可以查看**修改内容**。
-  用`git diff HEAD -- readme.txt`命令可以查看工作区和版本库里面最新版本的区别。
-  **提交修改和提交新文件**是一样的两步 。

## 版本回退

- `HEAD`指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令`git reset --hard commit_id`（版本号）。
  - HEAD^:上一个版本  
  - HEAD^^:上两个版本。
  - HEAD~100:上100个版本。
- 穿梭前，用`git log`可以查看**提交**历史，以便确定要**回退**到哪个版本。
- 要重返未来，用`git reflog`查看**命令**历史，以便确定要回到**未来**的哪个版本。

## 工作区和暂存区

-  Git和其他版本控制系统如SVN的一个不同之处就是有暂存区的概念。

- 工作区有一个**隐藏目录**`.git`，这个不算工作区，而是**Git的版本库**。

  Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的**暂存区**，还有Git为我们**自动创建**的第一个分支`master`，以及指向`master`的一个指针叫`HEAD`。

-   ![git-repo](https://www.liaoxuefeng.com/files/attachments/919020037470528/0) 

## 管理修改

-  `git add`命令实际上就是把要提交的所有修改放到暂存区（Stage），然后，执行`git commit`就可以一次性把暂存区的所有修改提交到分支(master)。 

-  如果不用`git add`到暂存区，那就不会加入到`commit`中。 

- 一旦提交后， 暂存区就没有任何内容了 。

- 如果你又没有对工作区做任何修改，那么工作区就是“干净”的：

  ```
  $ git status
  On branch master
  nothing to commit, working tree clean
  ```

## 撤销修改

- 命令`git checkout -- readme.txt`可以把`readme.txt`文件**在工作区的修改全部撤销**，这里有两种情况：

  > 一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

  > 一种是`readme.txt`已经添加到暂存区后，然后作了修改，现在，撤销修改就回到添加到暂存区后的状态。

  > 总之，就是让这个文件回到最近一次`git commit`或`git add`时的状态。

- `git checkout -- file`命令中的`--`很重要，没有`--`，就变成了“切换到另一个分支”的命令。

- 用命令`git reset HEAD `可以把**暂存区的修改**撤销掉（unstage），重新放回工作区：

  ```
  $ git reset HEAD readme.txt
  Unstaged changes after reset:
  M	readme.txt
  ```

  `git reset`命令既可以回退版本，也可以把暂存区的修改回退到工作区。当我们用`HEAD`时，表示最新的版本。

  再用`git status`查看一下，现在暂存区是干净的，工作区有修改。之后可用`git checkout -- file`把工作区的修改撤销掉。

  ### 小结

  >场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- file`。

  > 场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD `，就回到了场景1，第二步按场景1操作。

  > 场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退，不过前提是没有推送到远程库。

## 删除文件

- 一般情况下，你通常直接在文件管理器中把没用的文件删了，或者用`rm`命令删了：

  ```
  $ rm test.txt
  ```

  这个时候，Git知道你删除了文件，因此，工作区和版本库就不一致了，`git status`命令会立刻告诉你哪些文件被删除了。

- 现在你有两个选择:

  - 一是确实**要从版本库中删除该文件**，那就用命令`git rm`删掉，并且`git commit`：

  ```
  $ git rm test.txt
  rm 'test.txt'

  $ git commit -m "remove test.txt"
  [master d46f35e] remove test.txt
   1 file changed, 1 deletion(-)
   delete mode 100644 test.txt
  ```

  > 小提示：先手动删除文件，然后使用git rm <file>和git add<file>效果是一样的。

  - 另一种情况是删错了，因为版本库里还有呢，所以可以很轻松地**把误删的文件恢复到最新版本**：

  ```
  $ git checkout -- test.txt
  ```

  `git checkout`其实是**用版本库里的版本替换工作区的版本**，无论工作区是修改还是删除，都可以“一键还原”。

  > 注意：从来没有被添加到版本库就被删除的文件，是无法恢复的！

#### 远程仓库

- 将本地库与远程库关联:

  ```
  $ git remote add origin git@github.com:michaelliao/learngit.git
  ```

-  把本地库的所有内容推送到远程库上： 

  ```
  $ git push -u origin master
  ```

> 由于远程库是空的，我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支内容推送的远程新的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来，在以后的推送或者拉取时就可以不用-u.

