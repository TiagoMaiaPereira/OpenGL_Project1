#pragma once
#include <vector>;
#include <string>;
#include <map>;

class OBJModel
{
public:
	OBJModel();
	~OBJModel();

	void LoadFromFile(const char* filename);
	std::vector<float> GetVertexData();
	int GetVertexCount();
private:
	struct Position { float x, y, z; };
	struct Color { float r, g, b; };
	struct Normal { float x, y, z; };

	void LoadMaterialFile(const char* filename);
	bool StartWith(std::string& line, const char* text);

	std::map<std::string, Color> mMaterialMap;
	std::vector<float> mVertexData;

	void AddVertexData(int vIdx, int nIdx, const char* mtl,
		std::vector<Position>& vertices, std::vector<Normal>& normals);

};


