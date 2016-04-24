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

#include <taglib/tag.h>
#include <taglib/fileref.h>

#include "transcoder.h"

using namespace std;

Tag* Transcoder::ReadTag(string filename) {
	TagLib::FileRef f(filename.c_str(), false);

	if (f.tag() == NULL) {
		throw new invalid_argument("Error opening file");
	}

	return f.tag();
}



void Transcoder::WriteTag(string filename, char * tag) {
	return;
}


void Transcoder::PrintTag(Tag* tag) {

	printf("%s\n", tag->title().to8Bit().c_str());
	printf("%s\n", tag->artist().to8Bit().c_str());
	printf("%s\n", tag->album().to8Bit().c_str());
	printf("%s\n", tag->comment().to8Bit().c_str());
	printf("%s\n", tag->genre().to8Bit().c_str());
	printf("%u\n", tag->year());
	printf("%u\n", tag->track());

	return;
}
