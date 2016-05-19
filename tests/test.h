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

#ifndef ID3TOVORBIS_TEST_H_
#define ID3TOVORBIS_TEST_H_

#include <taglib/tag.h>

using namespace TagLib;

class TestId3Vorbis {
	private:
		Tag* tagId3;
		Tag* tagVorbis;

		void FillId3(Tag* t);
		void FillVorbis(Tag* t);
	public:
		TestId3Vorbis();
		~TestId3Vorbis();
		int CompareTags(Tag* tag1, Tag* tag2);
};

#endif /* ID3TOVORBIS_TEST_H_ */
