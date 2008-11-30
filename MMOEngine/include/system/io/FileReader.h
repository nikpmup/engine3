#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "File.h"

#include "Reader.h"

#include "FileNotFoundException.h"

namespace sys {
  namespace io {

  	class FileReader : public Reader {
  		File* file;

  		char buf[4096];

  	public:
  		FileReader(File* file) {
  			file->setReadOnly();

  			if (!file->exists())
  				throw FileNotFoundException(file);

  			FileReader::file = file;
  		}

  		void close() {
  			file->close();
  		}

  		int read(byte* buf, int len) {
  			return fread(buf, 1, len, file->getDescriptor());
  		}

  		int read(byte* buf, uint32 off, int len) {
  			file->seek(off);

  			return fread(buf, 1, len, file->getDescriptor());
  		}

  		bool readLine(String& line) {
  			if (fgets(buf, 4096, file->getDescriptor()) != NULL) {
  				line = buf;

  				return true;
  			} else
  				return false;
  		}

  		int skip(int n) {
  			return file->seek(n, SEEK_CUR);
  		}
  	};

  } // namespace io
} // namespace sys

using namespace sys::io;

#endif /*FILEREADER_H_*/
