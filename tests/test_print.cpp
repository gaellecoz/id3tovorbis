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

#include <stdio.h>
#include <stdlib.h>

#include "../src/transcoder.h"

using namespace std;

static string testFile1 ("audio_test_id3.m4a");
static string testFile2 ("audio_test_vorbis.ogg");

int main(void) {

	try {
		Tag* t;

		t = Transcoder::ReadTag(testFile1);
		Transcoder::PrintTag(t);

		t = Transcoder::ReadTag(testFile2);
		Transcoder::PrintTag(t);

		return EXIT_SUCCESS;
	} catch (const exception& e) {
		cout << e.what();
		return EXIT_FAILURE;
	}
}
