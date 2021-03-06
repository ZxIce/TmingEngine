
//= INCLUDES ===================
#include "FileStream.h"
//#include "../Scene/GameObject.h"
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Vector4.h"
#include "../Math/Quaternion.h"
#include "../Logging/Log.h"
//#include "../Graphics/Vertex.h"
#include <iostream>
//=============================

//= NAMESPACES ================
using namespace std;
using namespace TmingEngine::Math;
//=============================

namespace TmingEngine
{
	FileStream::FileStream(const string& path, FileStreamMode mode)
	{
		m_isOpen = false;
		m_mode = mode;

		if (mode == FileStreamMode_Write)
		{
			out.open(path, ios::out | ios::binary);
			if (out.fail())
			{
				LOG_ERROR("StreamIO: Failed to open \"" + path + "\" for writing.");
				return;
			}
		}
		else if (mode == FileStreamMode_Read)
		{
			in.open(path, ios::in | ios::binary);
			if(in.fail())
			{
				LOG_ERROR("StreamIO: Failed to open \"" + path + "\" for reading.");
				return;
			}
		}

		m_isOpen = true;
	}

	FileStream::~FileStream()
	{
		if (m_mode == FileStreamMode_Write)
		{
			out.flush();
			out.close();
		}
		else if (m_mode == FileStreamMode_Read)
		{
			in.clear();
			in.close();
		}
	}

	void FileStream::Write(const string& value)
	{
		unsigned int length = (unsigned int)value.length();
		Write(length);

		out.write(const_cast<char*>(value.c_str()), length);
	}

	void FileStream::Write(const vector<string>& value)
	{
		unsigned int size = (unsigned int)value.size();
		Write(size);

		for (unsigned int i = 0; i < size; i++)
		{
			Write(value[i]);
		}
	}

	void FileStream::Write(const Vector2& value)
	{
		out.write(reinterpret_cast<const char*>(&value), sizeof(Vector2));
	}

	void FileStream::Write(const Vector3& value)
	{
		out.write(reinterpret_cast<const char*>(&value), sizeof(Vector3));
	}

	void FileStream::Write(const Vector4& value)
	{
		out.write(reinterpret_cast<const char*>(&value), sizeof(Vector4));
	}

	void FileStream::Write(const Quaternion& value)
	{
		out.write(reinterpret_cast<const char*>(&value), sizeof(Quaternion));
	}

	void FileStream::Write(const vector<VertexPosTexTBN>& value)
	{
		unsigned int length = (unsigned int)value.size();
		Write(length);
		//out.write(reinterpret_cast<const char*>(&value[0]), sizeof(VertexPosTexTBN) * length);
	}

	void FileStream::Write(const vector<unsigned int>& value)
	{
		unsigned int length = (unsigned int)value.size();
		Write(length);
		out.write(reinterpret_cast<const char*>(&value[0]), sizeof(unsigned int) * length);
	}

	void FileStream::Write(const vector<unsigned char>& value)
	{
		unsigned int size = (unsigned int)value.size();
		Write(size);
		out.write(reinterpret_cast<const char*>(&value[0]), sizeof(unsigned char) * size);
	}

	void FileStream::Write(const vector<std::byte>& value)
	{
		unsigned int size = (unsigned int)value.size();
		Write(size);
		out.write(reinterpret_cast<const char*>(&value[0]), sizeof(std::byte) * size);
	}

	void FileStream::Read(string* value)
	{
		unsigned int length = 0;
		Read(&length);

		value->resize(length);
		in.read(const_cast<char*>(value->c_str()), length);
	}

	void FileStream::Read(Vector2* value)
	{
		in.read(reinterpret_cast<char*>(value), sizeof(Vector2));
	}

	void FileStream::Read(Vector3* value)
	{
		in.read(reinterpret_cast<char*>(value), sizeof(Vector3));
	}

	void FileStream::Read(Vector4* value)
	{
		in.read(reinterpret_cast<char*>(value), sizeof(Vector4));
	}

	void FileStream::Read(Quaternion* value)
	{
		in.read(reinterpret_cast<char*>(value), sizeof(Quaternion));
	}

	void FileStream::Read(vector<string>* vec)
	{
		if (!vec)
			return;

		vec->clear();
		vec->shrink_to_fit();

		unsigned int size = 0;
		Read(&size);

		string str;
		for (unsigned int i = 0; i < size; i++)
		{
			Read(&str);
			vec->emplace_back(str);
		}
	}

	void FileStream::Read(vector<VertexPosTexTBN>* vec)
	{
		if (!vec)
			return;

		vec->clear();
		vec->shrink_to_fit();

		unsigned int length = ReadUInt();

		vec->reserve(length);
		vec->resize(length);

		//in.read(reinterpret_cast<char*>(vec->data()), sizeof(VertexPosTexTBN) * length);
	}

	void FileStream::Read(vector<unsigned int>* vec)
	{
		if (!vec)
			return;

		vec->clear();
		vec->shrink_to_fit();

		unsigned int length = ReadUInt();

		vec->reserve(length);
		vec->resize(length);

		in.read(reinterpret_cast<char*>(vec->data()), sizeof(unsigned int) * length);
	}

	void FileStream::Read(vector<unsigned char>* vec)
	{
		if (!vec)
			return;

		vec->clear();
		vec->shrink_to_fit();

		unsigned int length = ReadUInt();

		vec->reserve(length);
		vec->resize(length);

		in.read(reinterpret_cast<char*>(vec->data()), sizeof(unsigned char) * length);
	}

	void FileStream::Read(vector<std::byte>* vec)
	{
		if (!vec)
			return;

		vec->clear();
		vec->shrink_to_fit();

		unsigned int length = ReadUInt();

		vec->reserve(length);
		vec->resize(length);

		in.read(reinterpret_cast<char*>(vec->data()), sizeof(std::byte) * length);
	}
}
