#pragma once
#include "Part.h"
#include "Body.h"

// Ό³Έν :
class Head : public Part
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	void Tick(float _Time);
	bool ScreenOutControl(int4& MovePos);
	bool DirControl(int4& MovePos);
	bool CheckBodyTrigger();
	void AddBody();
	void MovePart();

private:
	int4 currentDir = { 0, 1 };
};

