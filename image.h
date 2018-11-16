/* 
 * File:   image.h
 * Author: Tiago Dionizio
 *
 * Created on 7 de Novembro de 2018, 22:31
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <math.h>

#define imgALTURA 70
#define imgLARGURA 43

const unsigned char pixels[imgALTURA][imgLARGURA] = {
 0x45, 0x45, 0x43, 0x31, 0x30, 0x3c, 0x50, 0x5c, 0x65, 0x6d, 0x72, 0x70, 0x69, 0x63, 0x6a, 0x67, 0x66, 0x6d, 0x70, 0x78, 0x77, 0x74, 0x6d, 0x60, 0x5f, 0x6f, 0x7b, 0x85, 0x76, 0x6e, 0x68, 0x77, 0x80, 0x87, 0x89, 0x86, 0x77, 0x69, 0x68, 0x6f, 0x73, 0x6f, 0x66, 0x61, 0x62, 0x6a, 0x6b, 0x66, 0x61, 0x59, 0x4c, 0x3f, 0x39, 0x32, 0x2d, 0x29, 0x2a, 0x27, 0x20, 0x1f, 0x20, 0x21, 0x21, 0x1f, 0x1d, 0x1b, 0x1d, 0x1b, 0x1e, 0x27,
 0x45, 0x4d, 0x44, 0x2a, 0x2b, 0x36, 0x48, 0x58, 0x67, 0x6b, 0x6d, 0x69, 0x66, 0x69, 0x6d, 0x6f, 0x6f, 0x72, 0x72, 0x76, 0x71, 0x6f, 0x72, 0x6a, 0x7b, 0x7f, 0x67, 0x46, 0x35, 0x40, 0x45, 0x49, 0x4e, 0x59, 0x66, 0x88, 0x99, 0x9d, 0x94, 0x8d, 0x7d, 0x77, 0x70, 0x65, 0x60, 0x62, 0x61, 0x5b, 0x5c, 0x53, 0x4d, 0x45, 0x3b, 0x34, 0x2e, 0x27, 0x27, 0x29, 0x23, 0x1e, 0x1e, 0x26, 0x25, 0x21, 0x1f, 0x1e, 0x1f, 0x20, 0x25, 0x2d,
 0x47, 0x4b, 0x41, 0x26, 0x2a, 0x35, 0x44, 0x54, 0x65, 0x67, 0x63, 0x66, 0x67, 0x72, 0x76, 0x72, 0x71, 0x72, 0x73, 0x72, 0x72, 0x72, 0x79, 0x85, 0x87, 0x56, 0x2e, 0x2d, 0x24, 0x1c, 0x17, 0x1b, 0x1e, 0x21, 0x21, 0x2a, 0x56, 0x8c, 0xa8, 0xaf, 0xae, 0x9a, 0x78, 0x6e, 0x61, 0x5b, 0x5a, 0x59, 0x56, 0x52, 0x4f, 0x4c, 0x3e, 0x34, 0x2f, 0x2a, 0x29, 0x2a, 0x2a, 0x24, 0x27, 0x29, 0x28, 0x26, 0x24, 0x24, 0x24, 0x27, 0x2b, 0x39,
 0x34, 0x33, 0x28, 0x24, 0x2c, 0x38, 0x43, 0x4d, 0x55, 0x59, 0x56, 0x62, 0x6a, 0x6c, 0x6e, 0x6f, 0x6e, 0x75, 0x76, 0x77, 0x79, 0x85, 0x7e, 0x5a, 0x40, 0x30, 0x37, 0x26, 0x13, 0x13, 0xf, 0x1a, 0x2d, 0x2e, 0x3f, 0x4c, 0x57, 0x53, 0x7b, 0xad, 0xba, 0xc4, 0xb6, 0x8b, 0x64, 0x59, 0x57, 0x55, 0x55, 0x55, 0x50, 0x44, 0x3a, 0x38, 0x35, 0x36, 0x37, 0x3c, 0x39, 0x32, 0x31, 0x2d, 0x2e, 0x2c, 0x2a, 0x27, 0x28, 0x2c, 0x38, 0x4e,
 0x21, 0x20, 0x1e, 0x24, 0x2d, 0x3b, 0x3c, 0x3e, 0x43, 0x4b, 0x52, 0x57, 0x5f, 0x62, 0x63, 0x6a, 0x6c, 0x6e, 0x77, 0x7c, 0x8f, 0x82, 0x60, 0x24, 0x11, 0x24, 0x33, 0x1c, 0x10, 0xd, 0x12, 0x14, 0xd, 0xc, 0x1d, 0x41, 0x66, 0x86, 0x61, 0x67, 0x98, 0xbd, 0xd5, 0xc7, 0x90, 0x5e, 0x58, 0x54, 0x50, 0x4d, 0x45, 0x3b, 0x36, 0x33, 0x36, 0x3e, 0x4a, 0x4f, 0x4d, 0x45, 0x41, 0x3f, 0x3d, 0x35, 0x2f, 0x2b, 0x2a, 0x2f, 0x43, 0x5e,
 0x1a, 0x19, 0x19, 0x20, 0x2b, 0x34, 0x33, 0x35, 0x3c, 0x42, 0x4f, 0x54, 0x58, 0x5b, 0x60, 0x64, 0x67, 0x6d, 0x76, 0x83, 0x93, 0x57, 0x2e, 0x19, 0x1a, 0x19, 0x1b, 0x13, 0xd, 0xc, 0x15, 0x9, 0x2, 0x4, 0x7, 0x13, 0x37, 0x74, 0xb3, 0x89, 0x57, 0xa6, 0xc5, 0xd7, 0xcc, 0x97, 0x5f, 0x57, 0x54, 0x53, 0x4a, 0x42, 0x40, 0x3b, 0x3d, 0x47, 0x4e, 0x55, 0x59, 0x57, 0x51, 0x4f, 0x4c, 0x43, 0x33, 0x31, 0x2f, 0x3a, 0x56, 0x6e,
 0x15, 0x14, 0x17, 0x1d, 0x25, 0x2b, 0x2d, 0x32, 0x3e, 0x48, 0x50, 0x53, 0x54, 0x5a, 0x5f, 0x61, 0x65, 0x67, 0x75, 0x8c, 0x67, 0x39, 0x1d, 0x1f, 0x15, 0xb, 0x12, 0x10, 0x11, 0xa, 0xf, 0x8, 0x9, 0x9, 0xa, 0xc, 0x13, 0x2f, 0x76, 0xc3, 0x96, 0x82, 0xc4, 0xc0, 0xd3, 0xcf, 0x9a, 0x63, 0x5f, 0x5f, 0x58, 0x52, 0x4c, 0x4a, 0x4c, 0x4c, 0x50, 0x56, 0x58, 0x5b, 0x59, 0x53, 0x50, 0x43, 0x35, 0x30, 0x33, 0x49, 0x68, 0x7f,
 0xe, 0xf, 0x13, 0x18, 0x22, 0x29, 0x29, 0x33, 0x3d, 0x41, 0x4a, 0x50, 0x53, 0x5a, 0x5c, 0x5f, 0x66, 0x6a, 0x7c, 0x81, 0x4b, 0x2c, 0x1a, 0x24, 0x10, 0xa, 0x17, 0x14, 0x13, 0xc, 0xc, 0xb, 0x1b, 0x21, 0x13, 0x7, 0xb, 0x18, 0x46, 0x89, 0xc5, 0xa2, 0xb0, 0xce, 0xbc, 0xc7, 0xca, 0x94, 0x63, 0x65, 0x64, 0x60, 0x5c, 0x57, 0x59, 0x5c, 0x5e, 0x5c, 0x59, 0x58, 0x5a, 0x59, 0x55, 0x47, 0x39, 0x34, 0x41, 0x5f, 0x78, 0x8f,
 0xb, 0xe, 0x11, 0x15, 0x1d, 0x25, 0x27, 0x2a, 0x30, 0x3b, 0x47, 0x51, 0x51, 0x54, 0x56, 0x5c, 0x65, 0x6d, 0x91, 0x73, 0x4a, 0x1c, 0x28, 0x21, 0xf, 0x9, 0x12, 0x17, 0x16, 0x16, 0x11, 0x11, 0x1b, 0x2d, 0x40, 0x2d, 0x11, 0xe, 0x15, 0x4b, 0x94, 0xb8, 0x9e, 0xd0, 0xc8, 0xb9, 0xc9, 0xbe, 0x7e, 0x62, 0x65, 0x68, 0x65, 0x64, 0x64, 0x67, 0x6b, 0x68, 0x66, 0x5f, 0x5a, 0x5c, 0x57, 0x49, 0x40, 0x3f, 0x4f, 0x6f, 0x88, 0x93,
 0x9, 0xd, 0x12, 0x16, 0x1c, 0x23, 0x26, 0x29, 0x2c, 0x36, 0x43, 0x4d, 0x53, 0x55, 0x55, 0x55, 0x5e, 0x6d, 0xa2, 0x7e, 0x39, 0x21, 0x2c, 0x1d, 0xd, 0xe, 0x1b, 0x33, 0x41, 0x44, 0x48, 0x4f, 0x55, 0x58, 0x5e, 0x6d, 0x67, 0x4d, 0x3c, 0x31, 0x5b, 0x99, 0xb6, 0xaf, 0xd2, 0xb7, 0xba, 0xbf, 0xb5, 0x7d, 0x6e, 0x6f, 0x6e, 0x6a, 0x67, 0x68, 0x67, 0x66, 0x62, 0x61, 0x5b, 0x5a, 0x55, 0x4f, 0x43, 0x46, 0x5d, 0x7d, 0x90, 0x97,
 0xa, 0xc, 0x14, 0x18, 0x1e, 0x22, 0x28, 0x2c, 0x2c, 0x33, 0x42, 0x49, 0x52, 0x55, 0x55, 0x55, 0x58, 0x6d, 0x96, 0x76, 0x31, 0x3c, 0x38, 0x20, 0xf, 0x2c, 0x56, 0x7f, 0x93, 0x9a, 0xa1, 0xa6, 0xa6, 0x9d, 0x9d, 0x94, 0x9d, 0x98, 0x73, 0x5c, 0x45, 0x75, 0xa5, 0xb1, 0xc2, 0xc5, 0xb4, 0xb4, 0xbc, 0xb5, 0x7a, 0x71, 0x70, 0x68, 0x62, 0x66, 0x66, 0x5d, 0x54, 0x59, 0x5b, 0x5d, 0x56, 0x4c, 0x46, 0x49, 0x64, 0x85, 0x97, 0x92,
 0x9, 0xb, 0x13, 0x17, 0x1d, 0x23, 0x2d, 0x35, 0x35, 0x36, 0x42, 0x47, 0x50, 0x55, 0x53, 0x51, 0x5d, 0x71, 0x9b, 0x69, 0x3e, 0x46, 0x3d, 0x18, 0x1a, 0x4e, 0x84, 0xa9, 0xb9, 0xbe, 0xc2, 0xc1, 0xc0, 0xbb, 0xb8, 0xb2, 0xa7, 0xab, 0xa4, 0x8a, 0x67, 0x5f, 0x85, 0xac, 0xb2, 0xca, 0xb5, 0xb6, 0xa9, 0xc7, 0x9e, 0x64, 0x6c, 0x63, 0x61, 0x64, 0x63, 0x58, 0x53, 0x5b, 0x64, 0x65, 0x5f, 0x4e, 0x48, 0x4b, 0x67, 0x84, 0x94, 0x8f,
 0x9, 0xd, 0x12, 0x17, 0x1f, 0x29, 0x39, 0x41, 0x41, 0x42, 0x45, 0x47, 0x49, 0x51, 0x52, 0x52, 0x60, 0x70, 0x91, 0x73, 0x46, 0x4f, 0x3e, 0x16, 0x28, 0x6f, 0xa1, 0xbe, 0xca, 0xcd, 0xce, 0xcc, 0xcb, 0xcc, 0xc8, 0xc2, 0xb9, 0xb0, 0xb8, 0xb0, 0x8f, 0x61, 0x67, 0x8e, 0xaa, 0xc3, 0xbe, 0xac, 0xa5, 0xb0, 0xbe, 0x74, 0x62, 0x64, 0x5e, 0x5d, 0x5b, 0x57, 0x55, 0x5b, 0x64, 0x67, 0x61, 0x55, 0x4d, 0x52, 0x6c, 0x85, 0x8d, 0x85,
 0xa, 0xd, 0x12, 0x19, 0x20, 0x31, 0x41, 0x4b, 0x4d, 0x49, 0x47, 0x47, 0x47, 0x4a, 0x4e, 0x53, 0x5b, 0x87, 0x96, 0x6a, 0x49, 0x62, 0x47, 0x15, 0x33, 0x80, 0xae, 0xc5, 0xcd, 0xd1, 0xd4, 0xd3, 0xd4, 0xd6, 0xd4, 0xc9, 0xc6, 0xbf, 0xb7, 0xb8, 0xa7, 0x7a, 0x4c, 0x74, 0x99, 0xaf, 0xc4, 0xa9, 0xaf, 0xa0, 0xbd, 0xb6, 0x74, 0x6a, 0x5f, 0x5a, 0x58, 0x54, 0x58, 0x5e, 0x66, 0x68, 0x65, 0x57, 0x4f, 0x54, 0x6d, 0x7d, 0x7f, 0x75,
 0x6, 0xb, 0x12, 0x17, 0x22, 0x38, 0x47, 0x4e, 0x53, 0x4f, 0x46, 0x44, 0x47, 0x49, 0x4b, 0x4e, 0x53, 0x91, 0x92, 0x68, 0x47, 0x69, 0x42, 0x13, 0x30, 0x79, 0xae, 0xc5, 0xcd, 0xd1, 0xd4, 0xd6, 0xd8, 0xd9, 0xd4, 0xcd, 0xca, 0xc6, 0xbd, 0xb3, 0xaa, 0x92, 0x5c, 0x63, 0x93, 0xa5, 0xb5, 0xb6, 0xa4, 0xa6, 0xaa, 0xd0, 0xa1, 0x66, 0x62, 0x5c, 0x56, 0x53, 0x54, 0x5c, 0x66, 0x6c, 0x66, 0x57, 0x4e, 0x50, 0x5f, 0x6e, 0x69, 0x64,
 0x4, 0xb, 0x15, 0x19, 0x25, 0x37, 0x45, 0x4a, 0x4e, 0x4b, 0x44, 0x44, 0x46, 0x49, 0x4b, 0x4b, 0x59, 0x98, 0x92, 0x6c, 0x4d, 0x6d, 0x43, 0xf, 0x26, 0x6b, 0xa6, 0xc1, 0xcd, 0xd0, 0xd4, 0xd7, 0xdb, 0xdb, 0xd2, 0xce, 0xcf, 0xcc, 0xc5, 0xb9, 0xab, 0x9e, 0x75, 0x56, 0x6d, 0x9b, 0x9c, 0xbd, 0x9e, 0xb0, 0xa6, 0xc2, 0xc7, 0x7e, 0x61, 0x5b, 0x54, 0x52, 0x52, 0x56, 0x64, 0x68, 0x6a, 0x64, 0x56, 0x55, 0x5c, 0x60, 0x5a, 0x53,
 0x3, 0xc, 0x18, 0x1d, 0x24, 0x35, 0x41, 0x48, 0x4c, 0x4a, 0x48, 0x47, 0x47, 0x48, 0x4b, 0x4d, 0x62, 0xaf, 0xa7, 0x71, 0x54, 0x73, 0x48, 0x10, 0x27, 0x77, 0xb0, 0xc6, 0xd0, 0xd4, 0xd8, 0xda, 0xdd, 0xdd, 0xd6, 0xd2, 0xd1, 0xd0, 0xc7, 0xb8, 0x95, 0x7b, 0x67, 0x55, 0x66, 0x84, 0x96, 0xa9, 0xa0, 0xac, 0xa9, 0xb0, 0xcb, 0xae, 0x72, 0x5a, 0x4e, 0x4c, 0x4e, 0x4e, 0x59, 0x62, 0x69, 0x69, 0x62, 0x60, 0x5f, 0x61, 0x5c, 0x52,
 0x2, 0xd, 0x17, 0x1a, 0x21, 0x2d, 0x3d, 0x41, 0x44, 0x4b, 0x4d, 0x4e, 0x4e, 0x4c, 0x4d, 0x52, 0x6c, 0xb7, 0x93, 0x78, 0x54, 0x74, 0x57, 0x1a, 0x3e, 0x92, 0xbb, 0xc9, 0xc8, 0xb6, 0xb5, 0xb7, 0xb9, 0xc7, 0xcf, 0xd2, 0xd0, 0xd0, 0xc0, 0x93, 0x73, 0x75, 0x84, 0x6a, 0x68, 0x79, 0x94, 0x9e, 0xbb, 0xa3, 0xb2, 0x9f, 0xc2, 0xcf, 0x94, 0x67, 0x4f, 0x44, 0x43, 0x45, 0x4d, 0x58, 0x65, 0x6b, 0x6c, 0x62, 0x5e, 0x62, 0x62, 0x59,
 0x2, 0xe, 0x19, 0x1b, 0x22, 0x29, 0x37, 0x40, 0x42, 0x4a, 0x50, 0x53, 0x58, 0x5a, 0x5b, 0x5e, 0x84, 0xc1, 0x9b, 0x81, 0x5d, 0x6d, 0x63, 0x27, 0x50, 0x99, 0xb3, 0xa9, 0xa2, 0x9a, 0x97, 0x90, 0x8c, 0x96, 0xa2, 0xc8, 0xd1, 0xcd, 0xb6, 0x98, 0x78, 0x41, 0x3a, 0x48, 0x44, 0x78, 0x81, 0x92, 0xbc, 0xa9, 0xb5, 0xa3, 0xab, 0xcf, 0xb3, 0x7c, 0x58, 0x42, 0x3f, 0x42, 0x47, 0x4f, 0x56, 0x62, 0x63, 0x5c, 0x5c, 0x5d, 0x5b, 0x58,
 0x2, 0xa, 0x18, 0x1c, 0x25, 0x2e, 0x37, 0x40, 0x42, 0x4b, 0x54, 0x57, 0x5c, 0x68, 0x6d, 0x78, 0xad, 0xc3, 0x97, 0x75, 0x68, 0x74, 0x5e, 0x39, 0x4b, 0x96, 0xad, 0xbd, 0xc0, 0xa7, 0x8f, 0x8b, 0x8b, 0x98, 0xa8, 0xc2, 0xd2, 0xcb, 0x9f, 0x7c, 0x61, 0x5f, 0x45, 0x5a, 0x4f, 0x85, 0x76, 0x81, 0xa3, 0xbf, 0xaf, 0xba, 0xa2, 0xc0, 0xd1, 0x90, 0x61, 0x48, 0x3f, 0x41, 0x45, 0x4b, 0x4f, 0x57, 0x5c, 0x5a, 0x53, 0x52, 0x52, 0x52,
 0x3, 0x9, 0x15, 0x1a, 0x26, 0x34, 0x40, 0x47, 0x4d, 0x50, 0x56, 0x59, 0x5f, 0x6a, 0x7d, 0x88, 0xbf, 0xb1, 0x75, 0x66, 0x67, 0x71, 0x52, 0x4d, 0x45, 0x96, 0xb9, 0xaf, 0x63, 0x36, 0x48, 0x4f, 0x7f, 0x56, 0x7f, 0xb1, 0xcb, 0xcd, 0x9c, 0x85, 0x91, 0x96, 0x8b, 0x79, 0x73, 0x80, 0x76, 0x7b, 0x98, 0xc1, 0xbc, 0xc7, 0xb1, 0xb1, 0xd2, 0xc3, 0x76, 0x54, 0x4e, 0x40, 0x41, 0x42, 0x4a, 0x56, 0x57, 0x56, 0x50, 0x50, 0x4d, 0x52,
 0x7, 0xc, 0x18, 0x20, 0x2b, 0x3c, 0x49, 0x52, 0x56, 0x5b, 0x5f, 0x5f, 0x63, 0x6f, 0x86, 0x96, 0xb8, 0x95, 0x62, 0x66, 0x65, 0x69, 0x46, 0x4e, 0x48, 0x95, 0xbe, 0xb9, 0x94, 0x89, 0x8c, 0x86, 0x8d, 0x97, 0xa7, 0xb4, 0xc8, 0xd4, 0xb2, 0x91, 0x9f, 0xa1, 0x9c, 0x8f, 0x7e, 0x78, 0x84, 0x68, 0x91, 0xb5, 0xc3, 0xc2, 0xc2, 0xb5, 0xc5, 0xd3, 0xa9, 0x61, 0x54, 0x4d, 0x40, 0x43, 0x47, 0x4d, 0x50, 0x50, 0x4a, 0x4b, 0x4e, 0x4e,
 0xe, 0x15, 0x21, 0x28, 0x36, 0x46, 0x51, 0x60, 0x65, 0x6a, 0x66, 0x6a, 0x6c, 0x7b, 0x91, 0xab, 0xbc, 0x90, 0x5f, 0x68, 0x68, 0x67, 0x43, 0x44, 0x50, 0x8e, 0xbf, 0xcc, 0xcf, 0xcd, 0xc8, 0xc5, 0xc0, 0xc3, 0xc4, 0xc7, 0xd2, 0xd7, 0xc6, 0x9f, 0x9d, 0xac, 0xab, 0x9b, 0x7f, 0x75, 0x80, 0x7a, 0x80, 0xac, 0xbc, 0xc3, 0xc5, 0xbd, 0xc3, 0xc8, 0xbc, 0x91, 0x49, 0x51, 0x4a, 0x44, 0x43, 0x48, 0x4a, 0x4d, 0x49, 0x4c, 0x4d, 0x4a,
 0x17, 0x1f, 0x2c, 0x33, 0x3f, 0x4a, 0x59, 0x69, 0x71, 0x76, 0x75, 0x79, 0x7c, 0x8a, 0x9c, 0xaa, 0xc3, 0x93, 0x56, 0x65, 0x6a, 0x64, 0x4f, 0x38, 0x4b, 0x7b, 0xc2, 0xd3, 0xd6, 0xd7, 0xd6, 0xd3, 0xd3, 0xd3, 0xce, 0xd1, 0xd7, 0xda, 0xd0, 0xa8, 0x9a, 0xb3, 0xb7, 0xac, 0x8c, 0x71, 0x77, 0x87, 0x7d, 0x9d, 0xb7, 0xb9, 0xc4, 0xb9, 0xc5, 0xc4, 0xbe, 0xa7, 0x7c, 0x4c, 0x4e, 0x43, 0x41, 0x45, 0x46, 0x47, 0x46, 0x4b, 0x4b, 0x49,
 0x1e, 0x26, 0x30, 0x34, 0x3c, 0x4a, 0x5a, 0x6c, 0x76, 0x7f, 0x85, 0x85, 0x88, 0x98, 0x9f, 0xa9, 0xbf, 0x98, 0x57, 0x6e, 0x71, 0x68, 0x5e, 0x34, 0x4a, 0x5c, 0xb2, 0xd1, 0xd8, 0xdb, 0xdd, 0xdd, 0xdc, 0xd7, 0xcf, 0xc7, 0xd2, 0xdb, 0xd5, 0xba, 0x99, 0xa9, 0xb9, 0xb3, 0x94, 0x6d, 0x70, 0x76, 0x78, 0x89, 0xb3, 0xb5, 0xbe, 0xb1, 0xc3, 0xc6, 0xc7, 0xb4, 0x9b, 0x6a, 0x3f, 0x41, 0x41, 0x45, 0x46, 0x4c, 0x4c, 0x50, 0x4d, 0x4a,
 0x22, 0x2c, 0x33, 0x36, 0x3d, 0x4c, 0x5e, 0x6d, 0x7c, 0x87, 0x8e, 0x92, 0x94, 0x9b, 0xa0, 0xb2, 0xca, 0xb7, 0x6e, 0x74, 0x7d, 0x6c, 0x67, 0x3a, 0x46, 0x40, 0x82, 0xc3, 0xd7, 0xda, 0xdd, 0xe0, 0xde, 0xda, 0xc6, 0xc4, 0xd7, 0xde, 0xde, 0xd1, 0xac, 0xa3, 0xb0, 0xad, 0x93, 0x6a, 0x63, 0x77, 0x71, 0x83, 0xa0, 0xb2, 0xba, 0xb5, 0xb4, 0xcd, 0xca, 0xb9, 0x92, 0x7a, 0x52, 0x3a, 0x3f, 0x46, 0x49, 0x53, 0x50, 0x4d, 0x4d, 0x4f,
 0x25, 0x32, 0x38, 0x37, 0x3e, 0x4f, 0x5d, 0x6a, 0x7a, 0x84, 0x89, 0x8e, 0x8e, 0x97, 0xa5, 0xba, 0xda, 0xce, 0x89, 0x76, 0x76, 0x5d, 0x64, 0x4a, 0x3e, 0x3b, 0x4b, 0x9c, 0xc6, 0xd3, 0xd7, 0xda, 0xda, 0xd7, 0xc5, 0xc1, 0xcb, 0xcf, 0xd2, 0xc2, 0x9b, 0x97, 0x94, 0x92, 0x88, 0x57, 0x4d, 0x79, 0x61, 0x73, 0x99, 0xa3, 0xb4, 0xb8, 0xa6, 0xbf, 0xce, 0xc0, 0x95, 0x81, 0x65, 0x40, 0x44, 0x4d, 0x4f, 0x4f, 0x4f, 0x4c, 0x4c, 0x4f,
 0x27, 0x35, 0x3e, 0x3e, 0x44, 0x4f, 0x5b, 0x68, 0x70, 0x74, 0x7a, 0x80, 0x85, 0x91, 0xa3, 0xc4, 0xe0, 0xcc, 0x84, 0x73, 0x74, 0x55, 0x55, 0x56, 0x3b, 0x49, 0x35, 0x72, 0xae, 0xc7, 0xd1, 0xd6, 0xd5, 0xd1, 0xce, 0xc2, 0xba, 0xb7, 0xad, 0xa7, 0x9e, 0x95, 0x7f, 0x7a, 0x80, 0x46, 0x32, 0x6b, 0x6c, 0x5b, 0x8d, 0xa0, 0xa7, 0xb0, 0x9a, 0xab, 0xc5, 0xc5, 0xa5, 0x91, 0x66, 0x4d, 0x4c, 0x50, 0x52, 0x50, 0x51, 0x52, 0x54, 0x57,
 0x28, 0x37, 0x42, 0x46, 0x4a, 0x50, 0x5b, 0x67, 0x69, 0x6a, 0x6c, 0x73, 0x7e, 0x86, 0x94, 0xaf, 0xd3, 0xc2, 0x76, 0x67, 0x75, 0x62, 0x55, 0x65, 0x3f, 0x4c, 0x32, 0x52, 0x9b, 0xbb, 0xc9, 0xd1, 0xcc, 0xc9, 0xca, 0xc4, 0xb3, 0xa7, 0x9d, 0x90, 0x80, 0x66, 0x60, 0x79, 0x77, 0x3f, 0x15, 0x60, 0x7a, 0x5a, 0x77, 0x97, 0x9b, 0xac, 0x9b, 0x9e, 0xb1, 0xc4, 0xc1, 0x96, 0x7c, 0x58, 0x54, 0x5b, 0x55, 0x52, 0x50, 0x54, 0x59, 0x5d,
 0x21, 0x32, 0x42, 0x47, 0x4b, 0x50, 0x54, 0x5c, 0x5d, 0x5b, 0x5c, 0x66, 0x73, 0x7c, 0x8b, 0xa6, 0xd3, 0xc0, 0x76, 0x5d, 0x6c, 0x5f, 0x48, 0x64, 0x48, 0x42, 0x38, 0x34, 0x79, 0xaf, 0xbe, 0xc9, 0xca, 0xc2, 0xac, 0x8e, 0x84, 0x82, 0x7b, 0x74, 0x75, 0x70, 0x84, 0x78, 0x66, 0x27, 0x4, 0x41, 0x7b, 0x64, 0x5f, 0x8f, 0x96, 0xa4, 0x9b, 0x90, 0xa3, 0xb6, 0xc3, 0xb2, 0x89, 0x64, 0x59, 0x58, 0x51, 0x4e, 0x49, 0x4b, 0x53, 0x5a,
 0x1f, 0x30, 0x3e, 0x49, 0x4f, 0x50, 0x4c, 0x4f, 0x4f, 0x51, 0x52, 0x5d, 0x6c, 0x76, 0x89, 0x9c, 0xd1, 0xc2, 0x72, 0x57, 0x71, 0x62, 0x35, 0x4c, 0x59, 0x49, 0x43, 0x22, 0x55, 0x96, 0xae, 0xb8, 0xc1, 0xbf, 0xc1, 0xb8, 0xa9, 0xa0, 0x9b, 0x96, 0x96, 0x9d, 0x9e, 0x81, 0x53, 0xc, 0x1, 0x2e, 0x69, 0x7c, 0x50, 0x86, 0x96, 0x97, 0x93, 0x81, 0x9a, 0xae, 0xbb, 0xc1, 0x98, 0x63, 0x5e, 0x51, 0x4e, 0x48, 0x41, 0x42, 0x4b, 0x55,
 0x20, 0x2c, 0x3c, 0x49, 0x50, 0x55, 0x53, 0x51, 0x51, 0x56, 0x57, 0x5f, 0x6b, 0x82, 0x95, 0xa7, 0xd0, 0xc6, 0x79, 0x5e, 0x6f, 0x68, 0x34, 0x3d, 0x5e, 0x50, 0x47, 0x22, 0x32, 0x65, 0x9b, 0xac, 0xba, 0xbe, 0xc0, 0xc7, 0xc5, 0xc2, 0xb7, 0xb6, 0xb7, 0xb1, 0xa3, 0x83, 0x35, 0x1, 0x6, 0x31, 0x61, 0x85, 0x5f, 0x74, 0x98, 0x9b, 0x8d, 0x81, 0x8d, 0xa4, 0xb2, 0xba, 0xb5, 0x77, 0x64, 0x57, 0x4a, 0x44, 0x42, 0x3e, 0x45, 0x50,
 0x1a, 0x22, 0x37, 0x49, 0x53, 0x58, 0x59, 0x59, 0x59, 0x5c, 0x5f, 0x66, 0x7a, 0x97, 0x9a, 0xbd, 0xd8, 0xc4, 0x7b, 0x68, 0x6d, 0x6a, 0x38, 0x38, 0x5c, 0x5b, 0x50, 0x26, 0x26, 0x3f, 0x69, 0x93, 0xad, 0xba, 0xbf, 0xc7, 0xcd, 0xcb, 0xc3, 0xc0, 0xbd, 0xb0, 0xa6, 0x65, 0xf, 0x3, 0xd, 0x1c, 0x54, 0x78, 0x7b, 0x60, 0x95, 0x96, 0x92, 0x82, 0x85, 0xa7, 0xac, 0xb8, 0xba, 0xa8, 0x72, 0x5d, 0x51, 0x46, 0x42, 0x3d, 0x44, 0x4a,
 0x15, 0x1b, 0x2d, 0x42, 0x4e, 0x53, 0x56, 0x5d, 0x5e, 0x62, 0x68, 0x71, 0x84, 0x91, 0x9c, 0xc4, 0xd2, 0xbd, 0x68, 0x53, 0x6d, 0x60, 0x37, 0x2e, 0x4d, 0x57, 0x4d, 0x2b, 0x2a, 0x36, 0x53, 0x6a, 0x7d, 0x98, 0xb1, 0xc5, 0xcf, 0xd1, 0xce, 0xcb, 0xc7, 0xb7, 0x75, 0x14, 0x3, 0x6, 0x1a, 0x10, 0x38, 0x69, 0x84, 0x5f, 0x90, 0x8b, 0x8a, 0x78, 0x7a, 0x9f, 0xb3, 0xb7, 0xa7, 0xb2, 0xa5, 0x69, 0x51, 0x49, 0x43, 0x3e, 0x3f, 0x47,
 0x13, 0x1b, 0x2b, 0x3f, 0x4a, 0x51, 0x53, 0x5c, 0x5f, 0x5f, 0x68, 0x75, 0x82, 0x8b, 0xa3, 0xc4, 0xd0, 0xac, 0x59, 0x44, 0x69, 0x5e, 0x3c, 0x29, 0x46, 0x57, 0x56, 0x36, 0x21, 0x30, 0x4d, 0x61, 0x69, 0x7d, 0x93, 0xa5, 0xbc, 0xc8, 0xc9, 0xc0, 0xb2, 0x6d, 0xd, 0x0, 0x2, 0x5, 0x1f, 0xf, 0x1e, 0x66, 0x7f, 0x76, 0x88, 0x8d, 0x82, 0x72, 0x70, 0x94, 0xb8, 0xb8, 0xaa, 0x9e, 0xba, 0x94, 0x58, 0x4d, 0x47, 0x44, 0x46, 0x4a,
 0x12, 0x1c, 0x2c, 0x40, 0x49, 0x4f, 0x55, 0x57, 0x5a, 0x5c, 0x66, 0x72, 0x7e, 0x87, 0xa0, 0xb4, 0xc3, 0x93, 0x43, 0x45, 0x64, 0x52, 0x46, 0x31, 0x46, 0x56, 0x58, 0x39, 0x20, 0x31, 0x4d, 0x65, 0x76, 0x87, 0x92, 0x99, 0x9a, 0x97, 0x99, 0x8a, 0x64, 0x19, 0x0, 0x0, 0x0, 0x8, 0x23, 0x11, 0xd, 0x5a, 0x78, 0x8e, 0x7f, 0x96, 0x8f, 0x76, 0x6a, 0x85, 0xb1, 0xbc, 0xbd, 0x9c, 0xa4, 0xb5, 0x85, 0x5c, 0x52, 0x4d, 0x4b, 0x4e,
 0x13, 0x19, 0x29, 0x3e, 0x46, 0x4b, 0x50, 0x50, 0x4e, 0x53, 0x61, 0x6c, 0x7c, 0x86, 0xa6, 0xb8, 0xb1, 0x6f, 0x2d, 0x3f, 0x60, 0x44, 0x37, 0x37, 0x45, 0x4e, 0x59, 0x45, 0x23, 0x29, 0x4a, 0x68, 0x7b, 0x8a, 0x94, 0x9a, 0x99, 0x98, 0x93, 0x80, 0x4c, 0x14, 0x0, 0x0, 0x0, 0x9, 0x1c, 0x10, 0x4, 0x40, 0x75, 0x8b, 0x91, 0x95, 0x90, 0x60, 0x56, 0x79, 0xa2, 0xbc, 0xb4, 0xb5, 0x98, 0xab, 0xab, 0x79, 0x5d, 0x52, 0x4e, 0x51,
 0x13, 0x1a, 0x27, 0x35, 0x3c, 0x41, 0x46, 0x47, 0x43, 0x4c, 0x5d, 0x72, 0x80, 0x97, 0xa6, 0xa8, 0x95, 0x4e, 0x1d, 0x37, 0x63, 0x3e, 0x2a, 0x34, 0x47, 0x43, 0x4f, 0x52, 0x27, 0x23, 0x43, 0x67, 0x7d, 0x8d, 0x96, 0x98, 0x99, 0x9b, 0x97, 0x73, 0x40, 0x1a, 0x4, 0x0, 0x1, 0x8, 0x16, 0x10, 0x3, 0x29, 0x5c, 0x7b, 0x98, 0x88, 0x84, 0x6c, 0x42, 0x62, 0x93, 0xb5, 0xba, 0xc5, 0xa9, 0x9e, 0xa5, 0x9b, 0x69, 0x55, 0x50, 0x52,
 0x13, 0x18, 0x24, 0x33, 0x37, 0x3e, 0x41, 0x41, 0x3d, 0x44, 0x53, 0x6d, 0x82, 0x9c, 0x9d, 0x9e, 0x80, 0x35, 0xf, 0x40, 0x58, 0x3b, 0x30, 0x39, 0x45, 0x43, 0x40, 0x4e, 0x26, 0x23, 0x3f, 0x60, 0x7c, 0x8f, 0x97, 0x98, 0x9a, 0x9a, 0x8f, 0x65, 0x42, 0x28, 0xf, 0x2, 0x3, 0x6, 0x14, 0x15, 0x3, 0x24, 0x57, 0x6d, 0x93, 0x87, 0x7a, 0x7b, 0x3a, 0x4f, 0x84, 0xa9, 0xbd, 0xba, 0xc2, 0x98, 0xa1, 0x9f, 0x78, 0x5a, 0x54, 0x53,
 0x13, 0x19, 0x27, 0x32, 0x36, 0x3b, 0x3e, 0x3d, 0x3d, 0x44, 0x56, 0x69, 0x7e, 0x9d, 0xa1, 0xa1, 0x5c, 0x14, 0xa, 0x42, 0x3d, 0x39, 0x25, 0x29, 0x38, 0x40, 0x36, 0x4a, 0x29, 0x14, 0x32, 0x55, 0x73, 0x8a, 0x98, 0x98, 0x97, 0x96, 0x87, 0x5d, 0x49, 0x2f, 0x1d, 0x9, 0x5, 0x6, 0x10, 0x18, 0x2, 0x1d, 0x44, 0x6c, 0x8a, 0x85, 0x76, 0x70, 0x3d, 0x46, 0x76, 0x9c, 0xbb, 0xc1, 0xc0, 0xaa, 0x8b, 0x96, 0x89, 0x58, 0x5f, 0x50,
 0x18, 0x21, 0x2b, 0x2f, 0x33, 0x38, 0x3e, 0x3b, 0x39, 0x47, 0x5e, 0x7d, 0x9b, 0xa4, 0x97, 0x80, 0x2a, 0x3, 0x7, 0x29, 0x27, 0x3a, 0x1f, 0x1c, 0x2c, 0x35, 0x21, 0x3c, 0x28, 0x9, 0x1e, 0x44, 0x6d, 0x81, 0x8e, 0x8e, 0x89, 0x8e, 0x78, 0x4a, 0x34, 0x1f, 0x17, 0x10, 0x7, 0x4, 0xf, 0x12, 0x4, 0x11, 0x38, 0x5c, 0x79, 0x85, 0x6c, 0x67, 0x48, 0x3e, 0x6a, 0x8e, 0xb2, 0xdb, 0xe6, 0xd6, 0xa7, 0x92, 0x88, 0x5a, 0x52, 0x4b,
 0x1d, 0x25, 0x2c, 0x30, 0x36, 0x39, 0x4b, 0x61, 0x7c, 0x8e, 0xa5, 0xb0, 0xa2, 0x89, 0x6e, 0x4f, 0xd, 0x2, 0x12, 0x1d, 0x22, 0x36, 0x1b, 0x14, 0x19, 0x32, 0x18, 0x2a, 0x2e, 0x1a, 0x2d, 0x4e, 0x69, 0x74, 0x7b, 0x7b, 0x7e, 0x86, 0x6e, 0x4a, 0x34, 0x26, 0x20, 0x1c, 0xd, 0x2, 0xc, 0x13, 0x9, 0x8, 0x30, 0x44, 0x69, 0x7a, 0x74, 0x62, 0x50, 0x2b, 0x5b, 0x7f, 0xa8, 0xc1, 0xe5, 0xef, 0xd2, 0xa5, 0x89, 0x60, 0x53, 0x51,
 0x1e, 0x26, 0x2a, 0x32, 0x62, 0x91, 0xac, 0xbe, 0xbf, 0xb1, 0xa5, 0x94, 0x80, 0x76, 0x55, 0x2c, 0x4, 0x2, 0x1d, 0x14, 0x19, 0x34, 0x17, 0xe, 0x11, 0x32, 0x13, 0x1a, 0x2f, 0x33, 0x44, 0x61, 0x6b, 0x6f, 0x6f, 0x6f, 0x79, 0x7d, 0x78, 0x70, 0x5b, 0x45, 0x3c, 0x37, 0x1c, 0x3, 0x7, 0xd, 0xe, 0x2, 0x1e, 0x33, 0x53, 0x6e, 0x75, 0x64, 0x56, 0x35, 0x48, 0x79, 0xa0, 0xae, 0xcf, 0xeb, 0xea, 0xb9, 0x95, 0x6e, 0x53, 0x53
};


void Truncar_Pixel(int* pixel){
    if(*pixel > 255) *pixel = 255;
    if(*pixel < 0)   *pixel = 0;
}


unsigned char RobertsCross(short i, short j){
    int Gx;
    int Gy;
    int novo_pixel;
    if(i == imgALTURA - 1 || j == imgLARGURA - 1){
        if(i != imgALTURA - 1){
            Gx = (int)pixels[i][j] - 0;
            Gy = 0 - (int)pixels[i + 1][j];
        }
        else{
            if(j != imgLARGURA - 1){
                Gx = pixels[i][j] - 0;
                Gy = pixels[i][j + 1] - 0;
            }
            else{
                Gx = pixels[i][j];
                Gy = 0;
            }
        }
    }
    else{
        Gx = pixels[i][j] - pixels[i + 1][j + 1];
        Gy = pixels[i][j + 1] - pixels[i + 1][j];
    }
    
    novo_pixel = sqrt((Gx*Gx) + (Gy*Gy));
    Truncar_Pixel(&novo_pixel);
    return (unsigned char) novo_pixel;
}

#endif	/* IMAGE_H */

