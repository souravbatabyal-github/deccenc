// media_par.h
// Some media parameters.
/**
MIT License

Copyright (c) 2022 Sourav Batabyal

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

// media_io_type
enum media_io_type
{
	Media_IO_Type_None = 0,
	Media_IO_Type_Input = 1,
	Media_IO_Type_Filter = 2,
	Media_IO_Type_Output = 3
};

// media_handle_type
enum media_handle_type
{
	MediaHandleType_None = 0,
	MediaHandleType_File = 1, 
	MediaHandleType_Rtsp = 2, 
	MediaHandleType_Rtmp = 3
};

// media handle type identifiers
typedef struct media_handle_type_identifier
{
	static constexpr char* file = "file://";
	static constexpr char* rtsp = "rtsp://";
	static constexpr char* rtmp = "rtmp://";
}MediaHandleTypeIdentifier;
