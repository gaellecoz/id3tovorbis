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

#include <taglib/tag.h>
#include <taglib/toolkit/tpropertymap.h>
#include <taglib/ogg/xiphcomment.h>
#include <taglib/mpeg/id3v2/id3v2tag.h>

#include "test.h"

#define TEST_TAG_PROPERTY_ALBUM_NAME "ALBUM"
#define TEST_TAG_PROPERTY_ALBUMARTIST_NAME "ALBUMARTIST"
#define TEST_TAG_PROPERTY_ARTIST_NAME "ARTIST"
#define TEST_TAG_PROPERTY_DATE_NAME "DATE"
#define TEST_TAG_PROPERTY_DISCNUMBER_NAME "DISCNUMBER"
#define TEST_TAG_PROPERTY_TITLE_NAME "TITLE"
#define TEST_TAG_PROPERTY_TRACKNUMBER_NAME "TRACKNUMBER"

#define TEST_TAG_ALBUM_ID3 "id3 album"
#define TEST_TAG_ARTIST_ID3 "id3 artist"
#define TEST_TAG_TITLE_ID3 "id3 title"
#define TEST_TAG_TRACK_ID3 1
#define TEST_TAG_YEAR_ID3 2016

#define TEST_TAG_PROPERTY_ALBUM_ID3 "id3 album"
#define TEST_TAG_PROPERTY_ALBUMARTIST_ID3 "id3 album artist"
#define TEST_TAG_PROPERTY_ARTIST_ID3 "id3 artist"
#define TEST_TAG_PROPERTY_DATE_ID3 "2016"
#define TEST_TAG_PROPERTY_DISCNUMBER_ID3 "1/1"
#define TEST_TAG_PROPERTY_TITLE_ID3 "id3 title"
#define TEST_TAG_PROPERTY_TRACKNUMBER_ID3 "1/1"

/*
id3 title
id3 artist
id3 album


2016
1
-- TAG (properties) --
ALBUM       - "id3 album"
ALBUMARTIST - "id3 album artist"
ARTIST      - "id3 artist"
DATE        - "2016"
DISCNUMBER  - "1/1"
ENCODEDBY   - "Max 0.9.1"
TITLE       - "id3 title"
TRACKNUMBER - "1/1"
*/

TestId3Vorbis::TestId3Vorbis() {
	Tag* t;


	t = new ID3v2::Tag();
	tagId3 = t;

	t = new Ogg::XiphComment();
	tagVorbis = t;
}

TestId3Vorbis::~TestId3Vorbis() {
	if (tagId3) {
		delete(tagId3);
	}

	if (tagVorbis) {
		delete(tagVorbis);
	}
}

void TestId3Vorbis::FillId3(Tag* t) {

	t->setTitle(TEST_TAG_TITLE_ID3);
	t->setArtist(TEST_TAG_ARTIST_ID3);
	t->setAlbum(TEST_TAG_ALBUM_ID3);
	t->setYear(TEST_TAG_YEAR_ID3);
	t->setTrack(TEST_TAG_TRACK_ID3);

	TagLib::PropertyMap map = t->properties();
	map.insert(TEST_TAG_PROPERTY_ALBUM_NAME, TagLib::String(TEST_TAG_PROPERTY_ALBUM_ID3));
	map.insert(TEST_TAG_PROPERTY_ALBUMARTIST_NAME, TagLib::String(TEST_TAG_PROPERTY_ALBUMARTIST_ID3));
	map.insert(TEST_TAG_PROPERTY_ARTIST_NAME, TagLib::String(TEST_TAG_PROPERTY_ARTIST_ID3));
	map.insert(TEST_TAG_PROPERTY_DATE_NAME, TagLib::String(TEST_TAG_PROPERTY_DATE_ID3));
	map.insert(TEST_TAG_PROPERTY_DISCNUMBER_NAME, TagLib::String(TEST_TAG_PROPERTY_DISCNUMBER_ID3));
	map.insert(TEST_TAG_PROPERTY_TITLE_NAME, TagLib::String(TEST_TAG_PROPERTY_TITLE_ID3));
	map.insert(TEST_TAG_PROPERTY_TRACKNUMBER_NAME, TagLib::String(TEST_TAG_PROPERTY_TRACKNUMBER_ID3));

	//checkForRejectedProperties((*it).file()->setProperties(map));
}

void TestId3Vorbis::FillVorbis(Tag* t) {

	t->setTitle(TEST_TAG_TITLE_ID3);
	t->setArtist(TEST_TAG_ARTIST_ID3);
	t->setAlbum(TEST_TAG_ALBUM_ID3);
	t->setYear(TEST_TAG_YEAR_ID3);
	t->setTrack(TEST_TAG_TRACK_ID3);

	TagLib::PropertyMap map = t->properties();
	map.insert(TEST_TAG_PROPERTY_ALBUM_NAME, TagLib::String(TEST_TAG_PROPERTY_ALBUM_ID3));
	map.insert(TEST_TAG_PROPERTY_ALBUMARTIST_NAME, TagLib::String(TEST_TAG_PROPERTY_ALBUMARTIST_ID3));
	map.insert(TEST_TAG_PROPERTY_ARTIST_NAME, TagLib::String(TEST_TAG_PROPERTY_ARTIST_ID3));
	map.insert(TEST_TAG_PROPERTY_DATE_NAME, TagLib::String(TEST_TAG_PROPERTY_DATE_ID3));
	map.insert(TEST_TAG_PROPERTY_DISCNUMBER_NAME, TagLib::String(TEST_TAG_PROPERTY_DISCNUMBER_ID3));
	map.insert(TEST_TAG_PROPERTY_TITLE_NAME, TagLib::String(TEST_TAG_PROPERTY_TITLE_ID3));
	map.insert(TEST_TAG_PROPERTY_TRACKNUMBER_NAME, TagLib::String(TEST_TAG_PROPERTY_TRACKNUMBER_ID3));

	//checkForRejectedProperties((*it).file()->setProperties(map));
}

int TestId3Vorbis::CompareTags(Tag* tag1, Tag* tag2) {

	if (!tag1) {
		return 1;
	}
	if (!tag2) {
		return 1;
	}

	return 0;
}

