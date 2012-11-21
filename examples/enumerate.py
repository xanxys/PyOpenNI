#!/usr/bin/python
# ***** BEGIN GPL LICENSE BLOCK *****
#
# This file is part of PyOpenNI.
#
# PyOpenNI is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PyOpenNI is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
#
# PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
# OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
#
# ***** END GPL LICENSE BLOCK *****

"""
Prinn out list of Device nodes you can create.
"""

import openni

ctx = openni.Context()
ctx.init()

ns = ctx.enumerate_production_trees(openni.NODE_TYPE_DEVICE)
print len(ns), 'devices found'
for info in ns:
	print '========================================'
	print 'node_type', info.get_node_type()
	print 'vendor', info.get_vendor()
	print 'name', info.get_name()
	print 'version', info.get_version()

	print 'instance_name', info.get_instance_name()
	print 'creation_info', info.get_creation_info()
