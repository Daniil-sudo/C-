#include <SDL2/SDL.h> 
#include <vector>
#include <random>

// Параметры игры
const int GRID_SIZE = 50; // Размер сетки
const int CELL_SIZE = 10; // Размер клетки
const SDL_Color ALIVE_COLOR = {0, 255, 0, 255}; // Цвет живой клетки
const SDL_Color DEAD_COLOR = {0, 0, 0, 255}; // Цвет мертвой клетки

// Структура для хранения состояния клетки
struct Cell {
    bool alive;
};

// Функция для подсчета живых соседей
int countLivingNeighbors(const std::vector<std::vector<Cell>>& grid, int row, int col) {
    int neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Проверка выхода за границы поля
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE && !(i == row && j == col)) {
                if (grid[i][j].alive) {
                    neighbors++;
                }
            }
        }
    }
    return neighbors;
}

// Функция для обновления состояния игры
void updateGrid(std::vector<std::vector<Cell>>& grid) {
    std::vector<std::vector<Cell>> newGrid(GRID_SIZE, std::vector<Cell>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int neighbors = countLivingNeighbors(grid, i, j);

            // Правила игры "Жизнь"
            if (grid[i][j].alive && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j].alive = false;
            } else if (!grid[i][j].alive && neighbors == 3) {
                newGrid[i][j].alive = true;
            } else {
                newGrid[i][j].alive = grid[i][j].alive;
            }
        }
    }
    grid = newGrid;
}

int main(int argc, char* argv[]) {
    // Инициализация SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    // Создание окна
    SDL_Window* window = SDL_CreateWindow("Игра в жизнь", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                         GRID_SIZE * CELL_SIZE, GRID_SIZE * CELL_SIZE, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Создание рендера
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Создание игрового поля
    std::vector<std::vector<Cell>> grid(GRID_SIZE, std::vector<Cell>(GRID_SIZE));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = false;
        }
    }

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    // Инициализация случайного состояния
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = dis(gen);
        }
    }

    // Основной цикл игры
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Обновление состояния игры
        updateGrid(grid);

        // Отрисовка поля
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Очистка экрана
        SDL_RenderClear(renderer);
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j].alive) {
                    SDL_SetRenderDrawColor(renderer, ALIVE_COLOR.r, ALIVE_COLOR.g, ALIVE_COLOR.b, ALIVE_COLOR.a);
                } else {
                    SDL_SetRenderDrawColor(renderer, DEAD_COLOR.r, DEAD_COLOR.g, DEAD_COLOR.b, DEAD_COLOR.a);
                }
                SDL_Rect rect = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
        SDL_RenderPresent(renderer);

        // Задержка
        SDL_Delay(100); // Задержка в миллисекундах (100 = 0.1 сек)
    }

    // Очистка ресурсов
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}