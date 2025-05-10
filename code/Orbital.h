#ifndef ORBITAL_H
#define ORBITAL_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
using namespace sf;
using namespace std;

const float G = 100.0f; // Gravity constant
const float PI = 3.1415926535897932384626433;

class Orbital
{
	public:
		Orbital(Vector2f pos, Vector2f vel, float radius)
			: m_velocity(vel), m_position(pos)
		{
			m_radius = radius;
			m_shape.setRadius(m_radius);
			m_shape.setOrigin(m_radius, m_radius);
			m_shape.setPosition(pos);
			m_shape.setFillColor(Color::White);
		}
		void update(float deltaTime)
		{
			m_position += m_velocity * deltaTime;
			m_shape.setPosition(m_position);
		}
		void draw(RenderWindow& target)
		{
			target.draw(m_shape);
		}
		Vector2f getPosition() const { return m_position; }
		float getRadius() const { return m_radius; }

	private:
		CircleShape m_shape;
		float m_radius;
		Vector2f m_velocity;
		Vector2f m_position;

};

#endif
