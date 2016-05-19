/*******************************************************************************
 * id3tovorbis - Copy ID3 based tags to Vorbis based tags.
 * Copyright (c) 2016 Gaël Le Coz.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

/*
 *
 *  Created on: Apr 20, 2016
 *      Author: gaellecoz
 */

#include <cstdlib>
#include <cstddef>
//#include <cstdio>
#include <iomanip>

#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/mp4/mp4file.h>
#include <taglib/toolkit/tpropertymap.h>

#include "transcoder.h"

FileRef* Transcoder::ReadTag(string filename) {

	FileRef *f;

	f = new FileRef(filename.c_str(), false);

	if (f->isNull()) {
		throw new invalid_argument("Error opening file");
	}
	if (!f->tag()) {
		throw new invalid_argument("Error reading tag");
	}

	return f;
}

Tag* Transcoder::ReadTag(string filename, FileType type) {
	FileRef *f;

	switch (type) {
		case M4A:
			f = new FileRef(filename.c_str(), false);
		break;
		case OGG:
			f = new FileRef(filename.c_str(), false);;
		break;
	}


	if (f->tag() == NULL) {
		throw new invalid_argument("Error opening file");
	}

	return f->tag();
}



void Transcoder::WriteTag(string filename, Tag* tag) {
	if (filename.empty()) {
		throw new invalid_argument("filename is NULL");
	}
	if (tag == NULL) {
		throw new invalid_argument("tag is NULL");
	}
	return;
}


void Transcoder::PrintTag(FileRef* f) {

	if (!f) {
		throw new invalid_argument("Error opening file");
	}

	if (f->isNull()) {
		throw new invalid_argument("Error opening file");
	}

	if (!f->tag()) {
		throw new invalid_argument("Error opening file");
	}

	Tag *tag = f->tag();

	printf("%s\n", tag->title().to8Bit().c_str());
	printf("%s\n", tag->artist().to8Bit().c_str());
	printf("%s\n", tag->album().to8Bit().c_str());
	printf("%s\n", tag->comment().to8Bit().c_str());
	printf("%s\n", tag->genre().to8Bit().c_str());
	printf("%u\n", tag->year());
	printf("%u\n", tag->track());

    TagLib::PropertyMap tags = f->file()->properties();

    unsigned int longest = 0;
    for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
      if (i->first.size() > longest) {
        longest = i->first.size();
      }
    }

    cout << "-- TAG (properties) --" << endl;
    for(TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
      for(TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
        cout << left << std::setw(longest) << i->first << " - " << '"' << *j << '"' << endl;
      }
    }

  if(!f->audioProperties()) {
		throw new invalid_argument("Error reading audio properties");
  }

    TagLib::AudioProperties *properties = f->audioProperties();

    int seconds = properties->length() % 60;
    int minutes = (properties->length() - seconds) / 60;

    cout << "-- AUDIO --" << endl;
    cout << "bitrate     - " << properties->bitrate() << endl;
    cout << "sample rate - " << properties->sampleRate() << endl;
    cout << "channels    - " << properties->channels() << endl;
    cout << "length      - " << minutes << ":" << setfill('0') << setw(2) << seconds << endl;

	return;
}
