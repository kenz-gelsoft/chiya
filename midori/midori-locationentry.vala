/*
 Copyright (C) 2015 KENZ <KENZ.gelsoft@gmail.com>

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 See the file COPYING for the full license text.
*/

namespace Midori {
	public class LocationEntry : Gtk.Entry {
		public override void get_preferred_width (out int minimum_width,
		                                          out int natural_width) {
			// uses natural width
			minimum_width = -1;
			natural_width = 848;
		}
	}	
}
