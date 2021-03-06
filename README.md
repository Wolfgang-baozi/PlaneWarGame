# PlaneWarGame
飞机大战，一份课程实践作业，也是人生中的第一个小游戏。

## 1.需求分析
### 1.1功能需求
战机数量为1，由玩家通过键盘控制（方向键控制位置、空格键发射导弹）战机，我方子弹释放存在间隔，有一定的运行速度，我方子弹遇到敌机发生爆炸，敌机被炸毁，子弹消失，玩家得分。敌机自动向战机发动攻击，敌机数量随机，计算机生成敌机时随机选择类别，敌机从游戏区域的上下两端进入，具有一定的生命值，左右位置随机。敌机子弹对战机造成伤害，直至战机血量减少为0，游戏结束。

### 1.2数据需求
游戏中需要记录战机得分情况，所以具体的的分规则是战机击中敌机后得到相应的分值，由于敌机类型随机产生，战机被敌机击中则减对应的生命值，战机若与敌机相撞则生命值减对应的分数；战机击中boss后得分，战机被boss击中或与BOSS相撞时减去生命值；当战机生命值减为0时，游戏结束。游戏中的数据大部分是随机的例如敌机的个数，发射子弹的个数，出现时间，发射子弹实际都是随机的，所以该游戏对数据的需求不是很明确。

### 1.3行为需求
每一个函数都有特定的功能，也有一定的联系，大部分的函数是在OnTime函数和OnDraw函数中使用的，例如每个类都有的Draw函数和Move函数是必须要在这两个函数中使用的，否则每个对象的位置是不会随时间的变化而变化的。

## 2.主要功能模块
### 2.1玩家模块
（1）监测键盘按键，控制战机移动  
（2）监测键盘按键，来控制战机释放子弹  
（3）游戏选择，监测窗口中鼠标左键的点击时间，选择游戏模式或者帮助  
（4）进行游戏的暂停  
（5）点击B键开启无敌模式  
### 2.2规则模块
#### 攻击规则
敌机随机发射子弹，且敌机发射的子弹的方向与速度也是随机的
#### 碰撞规则
（1）战机所在矩形区域与道具所在矩形区域相交时，表示战机获得该奖励  
（2）子弹或炸弹本身的矩形区域和敌机或战机的矩形区域相交时，表示子弹或炸弹击中了敌机或战机  
（3）敌机击中战机，战机所掉的血量会根据战机的破坏力来定  
（4）战机击中敌机，敌机根据子弹的伤害掉指定的血量，敌机血量小于等于零，敌机炸毁  
（5）战机被炸毁，游戏结束  
### 2.3敌机模块
（1）敌机的初始位置是随机的  
（2）敌机会根据其子弹的冷却时间来发射子弹，每架敌机只能发射一发子弹  
（3）敌机血量为零后，敌机爆炸  

## 流程图示：
![Image text](https://raw.githubusercontent.com/Wolfgang-baozi/PlaneWarGame/main/img-folder/image1.png)
