#include "Game.h"


void runGame() {
    RenderWindow window(VideoMode(240, 360), "TETRIS GAME"); //render window

    Block block;
    if (!block.loadTexture("greenblock.png")) { //if loading of texture fails
        return;
    }

    Sprite sprite;
    sprite.setTexture(block.getTexture()); //set sprite as a texture

    vector<Figure> figures;  //vector of figures

    vector<Color> colors = {  //vector of colors
        Color::Red,
        Color::Blue,
        Color::Green,
        Color::Yellow,
        Color::Magenta,
        Color::Cyan,
        Color(255, 128, 0),
        Color(128, 0, 255)
    };

    for (int i = 0; i < 8; i++) {  //eight figures
        Figure figure;  
        figure.setFigure(i);  //figures 
        figure.setColor(colors[i]);  //assign color to each figure
        figures.push_back(figure);  //push figure back into vector
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();  //set seed
    std::shuffle(figures.begin(), figures.end(), std::default_random_engine(seed));  //shuffle figures in a vector 

    vector<vector<pair<int, Color>>> playfield(PLAYFIELD_HEIGHT, vector<pair<int, Color>>(PLAYFIELD_WIDTH, { 0, Color::White })); /*defines vector of vectors of type playfield,
     initializes the playfield vector with dimensions PLAYFIELD_HEIGHT by PLAYFIELD_WIDTH, each element of the playfield is initialized with 
     a pair containing 0 (representing an empty block) and Color::White (representing the color of the block).*/
   
    Clock clock; 
    float Time = 0.0f; 
    float delay = 0.3f; //delay with which figure moves down

    while (window.isOpen()) { 
        Event event;
        while (window.pollEvent(event)) {   //rotate figures, if collision detected, it returns initial positions
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Left) {
                    Figure& currentFigure = figures[0];
                    currentFigure.moveLeft();
                    if (currentFigure.checkCollision(playfield, figures)) {
                        currentFigure.moveRight();
                    }
                }
                if (event.key.code == Keyboard::Right) {
                    Figure& currentFigure = figures[0];
                    currentFigure.moveRight();
                    if (currentFigure.checkCollision(playfield, figures)) {
                        currentFigure.moveLeft();
                    }
                }
                if (event.key.code == Keyboard::R) {
                    Figure& currentFigure = figures[0];
                    currentFigure.rotateby90();
                    if (currentFigure.checkCollision(playfield, figures)) {
                        currentFigure.rotateby270();
                    }
                }
                if (event.key.code == Keyboard::T) {
                    Figure& currentFigure = figures[0];
                    currentFigure.rotateby90();
                    currentFigure.rotateby90();
                    if (currentFigure.checkCollision(playfield, figures)) {
                        currentFigure.rotateby90();
                        currentFigure.rotateby90();
                        
                    }
                }
                if (event.key.code == Keyboard::Y) {
                    Figure& currentFigure = figures[0];
                    currentFigure.rotateby270();
                    if (currentFigure.checkCollision(playfield, figures)) {
                        currentFigure.rotateby90();
                    }
                }
            }
        }

        Time += clock.restart().asSeconds(); //accumulate time

        if (Time >= delay) {   //if time passed is larger than delay, move figure
            Figure& currentFigure = figures[0]; //assign figures[0] to currentfigure, so that we can manipulate it 

            for (auto& block : currentFigure.blocks) { //move a figure down
                block.y++;
            }

            if (currentFigure.checkCollision(playfield, figures)) {  //if collision with bottom boundary detected,, return a figure to initial position
                for (auto& block : currentFigure.blocks) {
                    block.y--;
                }

                for (const auto& block : currentFigure.blocks) {
                    int x = block.x;
                    int y = block.y;

                    if (y >= 0) {
                        playfield[y][x] = { 1, currentFigure.getColor() }; //if figure has not collided with the bottom boundary yet, 1 means  
                                                                           // that the position is occupied by a block of the current figure
                    }
                }

                figures.erase(figures.begin()); //erase used figure from the vector

                Figure nextFigure; //set nextfigure
                nextFigure.setFigure(rand() % 8); //set random figure
                nextFigure.setColor(colors[rand() % colors.size()]); //assign random color
                figures.push_back(nextFigure); //push back figure to the vector

                removeFullRows(playfield);  
            }

            Time = 0.0f;
        }

        window.clear();


       

        for (int i = 0; i < PLAYFIELD_HEIGHT; i++) {
            for (int j = 0; j < PLAYFIELD_WIDTH; j++) {
                if (playfield[i][j].first != 0) {
                    sprite.setPosition(j * blockSize - xOffset, i * blockSize - yOffset);
                    sprite.setColor(playfield[i][j].second);
                    window.draw(sprite);
                }
            }
        }

        for (const auto& block : figures[0].blocks) {
            int x = block.x;
            int y = block.y;

            sprite.setPosition(x * blockSize - xOffset, y * blockSize - yOffset);
            sprite.setColor(figures[0].getColor());
            window.draw(sprite);
        }

        window.display();
    }
}

