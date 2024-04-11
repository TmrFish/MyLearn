import random
class Game:
    def _init_(self):
        self.number = 0

    def computer_turn(self):
        x = 0
        n = 0
        if self.number == 2:
            n = 1
        elif self.number ==1:
            print('游戏结束，玩家获胜')
            return 0
        else:
            while True:
                if pow(2,x)<self.number <= pow(2,x+1):
                    break
                x = x + 1
            if self.number == pow(2,x+1):
                n = random.randint(1,int(self.number / 2))
            else:
                n = self.number - (pow(2,x)-1)
        return n

    def player_turn(self):
        if self.number ==1:
                print('游戏结束电脑获胜')
                return 0
        n = int(input('请输入要拿走的物品个数:'))
        flag = n<1or n> int(self.number / 2)
        while flag:
            print('输入数据不符合游戏规则请重新输入')
            n = int(input('请输入要拿走的物品个数:'))
            flag = n < 1 or n > int(self.number /2)
        return n

    def begin(self):
        computer = 0
        player = 0
        print('欢迎来到尼姆游戏!')
        self.number = int(input('请输入物品总数:'))
        while True:
            computer = self.computer_turn()
            if computer == 0:
                break
            else:
                self.number = self.number - computer
                print('电脑回合:拿走{:d}个物品，剩余{:d}个物品'.format(computer,self.number))
                player = self.player_turn()
                if player == 0:
                    break
                else:
                    self.number = self.number - player
                    print('玩家回合:拿走{:d}个物品，剩余{:d}个物品'.format(player,self.number))

if __name__ == '__main__':
    game = Game()
    game.begin()