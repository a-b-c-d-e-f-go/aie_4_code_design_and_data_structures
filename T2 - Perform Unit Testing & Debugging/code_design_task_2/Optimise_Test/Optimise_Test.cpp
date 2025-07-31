#include "pch.h"
#include "CppUnitTest.h"
#include "Map.h"
#include "raylib.h"
#include "raymath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OptimiseTestClasses
{
	TEST_CLASS(MapTests)
	{
	public:

		TEST_METHOD(DefaultConstructor) //Check that the map's nodes are valid.
		{
			Map m = Map();
			forxy
				Assert::IsNotNull(m.nodes[x][y]);
			_forxy
		}
		TEST_METHOD(AddCritter) //Check if a critter will be added to the appropriate node.
		{
			//Create a new map and critter.
			Map m = Map();
			Critter c = Critter();
			c.Init(Vector2{ 15, 15 }, Vector2{ 0, 0 });

			//Attempt to add the critter to the map.
			m.Collisions(&c);

			//Do the math to find where the critter SHOULD be.
			size_t tx = (size_t)(c.GetX() / (float)NODE_WIDTH);
			size_t ty = (size_t)(c.GetY() / (float)NODE_HEIGHT);
			Node* n = m.nodes[tx][ty];

			//Check if that newly created node now has 1 critter.
			Assert::AreEqual(n->critters.size(), (size_t)1);
		}
	};

	TEST_CLASS(NodeTests)
	{
	public:

		TEST_METHOD(DefaultConstructor) //Bounds initialises to 0,0,0,0 by default.
		{
			Node n = Node();
			Assert::AreEqual(n.bounds.min.x, 0.0f);
			Assert::AreEqual(n.bounds.min.y, 0.0f);
			Assert::AreEqual(n.bounds.max.x, 0.0f);
			Assert::AreEqual(n.bounds.max.y, 0.0f);
		}
		TEST_METHOD(BoundsConstructor) //Bounds initialises to 1,2,3,4 with this AABB constructor.
		{
			Node n = Node(AABB{ Vector2{1, 2}, Vector2{3, 4} });
			Assert::AreEqual(n.bounds.min.x, 1.0f);
			Assert::AreEqual(n.bounds.min.y, 2.0f);
			Assert::AreEqual(n.bounds.max.x, 3.0f);
			Assert::AreEqual(n.bounds.max.y, 4.0f);
		}
	};
}