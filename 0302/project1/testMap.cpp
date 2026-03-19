#include <cassert>
#include <string>

#include "Map.h"

template <typename T>
T makeSample(int i)
{
	return static_cast<T>(i);
}

template <>
std::string makeSample<std::string>(int i)
{
	if (i == 1) return "a";
	if (i == 2) return "b";
	if (i == 3) return "c";
	if (i == 7) return "g";
	if (i == 8) return "h";
	if (i == 99) return "z";
	return "k" + std::to_string(i);
}

template <>
char makeSample<char>(int i)
{
	return static_cast<char>('a' + (i % 26));
}

int main()
{
	Map m;

	assert(m.empty());
	assert(m.size() == 0);

	const KeyType k1 = makeSample<KeyType>(1);
	const KeyType k2 = makeSample<KeyType>(2);
	const KeyType k3 = makeSample<KeyType>(3);
	const KeyType kMissing = makeSample<KeyType>(99);

	const ValueType v1 = makeSample<ValueType>(10);
	const ValueType v2 = makeSample<ValueType>(20);
	const ValueType v3 = makeSample<ValueType>(30);
	const ValueType v2New = makeSample<ValueType>(200);

	assert(m.insert(k1, v1));
	assert(m.insert(k2, v2));
	assert(!m.insert(k2, v3));
	assert(!m.empty());
	assert(m.size() == 2);

	assert(m.contains(k1));
	assert(!m.contains(kMissing));

	ValueType out = makeSample<ValueType>(-1);
	assert(m.get(k1, out));
	assert(out == v1);
	assert(!m.get(kMissing, out));

	assert(m.update(k2, v2New));
	out = makeSample<ValueType>(-1);
	assert(m.get(k2, out) && out == v2New);
	assert(!m.update(kMissing, v3));

	assert(m.insertOrUpdate(k3, v3));
	assert(m.size() == 3);

	const ValueType v3New = makeSample<ValueType>(300);
	assert(m.insertOrUpdate(k3, v3New));
	out = makeSample<ValueType>(-1);
	assert(m.get(k3, out) && out == v3New);

	KeyType gotK{};
	ValueType gotV{};
	bool orderOk = true;

	if (!(m.get(0, gotK, gotV) && gotK == k1 && gotV == v1))
		orderOk = false;
	if (!(m.get(1, gotK, gotV) && gotK == k2 && gotV == v2New))
		orderOk = false;
	if (!(m.get(2, gotK, gotV) && gotK == k3 && gotV == v3New))
		orderOk = false;

	assert(orderOk);
	assert(!m.get(3, gotK, gotV));

	assert(m.erase(k2));
	assert(!m.contains(k2));
	assert(m.size() == 2);
	assert(!m.erase(kMissing));

	Map a;
	Map b;
	const KeyType ka = makeSample<KeyType>(7);
	const ValueType va = makeSample<ValueType>(70);
	const KeyType kb = makeSample<KeyType>(8);
	const ValueType vb = makeSample<ValueType>(80);
	a.insert(ka, va);
	b.insert(kb, vb);
	a.swap(b);

	ValueType verifyA{};
	ValueType verifyB{};
	assert(a.contains(kb) && a.get(kb, verifyA) && verifyA == vb);
	assert(b.contains(ka) && b.get(ka, verifyB) && verifyB == va);

	// Capacity test for insert().
	Map full;
	bool capacityBehavior = true;
	for (int i = 0; i < 150; ++i)
	{
		if (!full.insert(makeSample<KeyType>(1000 + i), makeSample<ValueType>(2000 + i)))
		{
			capacityBehavior = false;
			break;
		}
	}
	if (capacityBehavior)
	{
		capacityBehavior = !full.insert(makeSample<KeyType>(99999), makeSample<ValueType>(99999));
	}
	assert(capacityBehavior);
	return 0;
}
