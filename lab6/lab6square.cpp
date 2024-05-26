#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
class Point {
protected:
    sf::Vector2f position;
    sf::Color color;

public:
    Point(float x = 0, float y = 0, sf::Color color = sf::Color::White)
        : position(x, y), color(color) {}

    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void move(float dx, float dy) { position.x += dx; position.y += dy; }
    virtual void setColor(sf::Color newColor) { color = newColor; }
    virtual void rotate(float angle) = 0;
    virtual void setSize(float size) = 0;

    virtual ~Point() = default;
};


class Square : public Point {
private:
    float size;
    float rotation;

public:
    Square(float x = 0, float y = 0, float size = 50, sf::Color color = sf::Color::Red)
        : Point(x, y, color), size(size), rotation(0) {}

    void draw(sf::RenderWindow& window) const override {
        sf::RectangleShape rectangle(sf::Vector2f(size, size));
        rectangle.setPosition(position);
        rectangle.setFillColor(color);
        rectangle.setRotation(rotation);
        window.draw(rectangle);
    }

    void rotate(float angle) override {
        rotation += angle;
    }

    void setSize(float newSize) override {
        size = newSize;
    }
};


void displayMenu() {
    cout << "1. Create Square\n";
    cout << "2. Move Square\n";
    cout << "3. Change Square Color\n";
    cout << "4. Rotate Square\n";
    cout << "5. Resize Square\n";
    cout << "6. Exit\n";
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphics Objects");

    Square* square = nullptr;
    bool running = true;

    while (window.isOpen() && running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (square) {
            square->draw(window);
        }

        window.display();

        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            float x, y, size;
            cout << "Enter x, y, size: ";
            cin >> x >> y >> size;
            delete square;
            square = new Square(x, y, size);
            break;
        }
        case 2: {
            if (square) {
                float dx, dy;
                cout << "Enter dx, dy: ";
                cin >> dx >> dy;
                square->move(dx, dy);
            }
            break;
        }
        case 3: {
            if (square) {
                int r, g, b;
                cout << "Enter r, g, b: ";
                cin >> r >> g >> b;
                square->setColor(sf::Color(r, g, b));
            }
            break;
        }
        case 4: {
            if (square) {
                float angle;
                cout << "Enter angle: ";
                cin >> angle;
                square->rotate(angle);
            }
            break;
        }
        case 5: {
            if (square) {
                float newSize;
                cout << "Enter new size: ";
                cin >> newSize;
                square->setSize(newSize);
            }
            break;
        }
        case 6: {
            running = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    delete square;
    return 0;
}