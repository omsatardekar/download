#include <SFML/Graphics.hpp> 
#include <vector> 
class ShapeDrawer { 
public: 
    virtual void draw(sf::RenderWindow &window) = 0; 
}; 
 
class ConcavePolygon : public ShapeDrawer { 
public: 
    ConcavePolygon(const std::vector<sf::Vector2f> &points, const sf::Color &color) 
        : m_points(points), m_color(color) { 
        if (m_points.size() >= 3) { 
            m_polygon.setPointCount(m_points.size()); 
            for (size_t i = 0; i < m_points.size(); ++i) { 
                m_polygon.setPoint(i, m_points[i]); 
            } 
            m_polygon.setFillColor(m_color); 
        } 
    } 
 
    void draw(sf::RenderWindow &window) override { 
        window.draw(m_polygon); 
    } 
 
private: 
    std::vector<sf::Vector2f> m_points; 
    sf::Color m_color; 
    sf::ConvexShape m_polygon; 
}; 
 
int main() { 
    sf::RenderWindow window(sf::VideoMode(800, 600), "Concave Polygon Fill"); 
    std::vector<sf::Vector2f> points = { 
        {100, 100}, 
        {300, 100}, 
        {400, 200}, 
        {300, 300}, 
        {100, 300}, 
        {50, 200} 
    }; 
    sf::Color fillColor = sf::Color::Green; 
    ConcavePolygon concavePolygon(points, fillColor); 
 
    while (window.isOpen()) { 
        sf::Event event; 
        while (window.pollEvent(event)) { 
            if (event.type == sf::Event::Closed) { 
                window.close(); 
            } 
        } 
 
        window.clear(sf::Color::White); 
        concavePolygon.draw(window); 
        window.display(); 
    } 
 
    return 0; 
} 
