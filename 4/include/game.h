#ifndef GAME_H_
#define GAME_H_
class Game
{
private:
    int answer;
    void Start();
    void End();
    void Win();
    int Input();

public:
    Game();
    ~Game();
    void Init();
};
#endif