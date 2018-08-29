/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef SFGE_EXT_PLANET_SYSTEM_H
#define SFGE_EXT_PLANET_SYSTEM_H

#include <engine/system.h>
#include <SFML/Graphics/VertexArray.hpp>
#include <Box2D/Common/b2Math.h>


namespace sfge
{
class Transform2d;
class Transform2dManager;
class Body2dManager;
class TextureManager;
class SpriteManager;
}
namespace sfge::ext
{



class PlanetSystem : public System
{
public:
	PlanetSystem(Engine& engine);

	void Init() override;

	void Update(float dt) override;

	void FixedUpdate() override;

private:
	b2Vec2 CalculateInitSpeed(Transform2d* transformPtr);
	b2Vec2 CalculateNewForce(Transform2d* transformPtr);
	float Magnitude(sf::Vector2f v);
	float Magnitude(b2Vec2 v);

	Transform2dManager& m_Transform2DManager;
	Body2dManager& m_Body2DManager;
	TextureManager& m_TextureManager;
	SpriteManager& m_SpriteManager;

	const float gravityConst = 1000.0f;
	const float centerMass = 1000.0f;
	const float planetMass = 1.0f;
	const int entitiesNmb = 10'000;
	sf::Vector2f screenSize;
	sf::VertexArray m_VertexArray;

};


}

#endif
