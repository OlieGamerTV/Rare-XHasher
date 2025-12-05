#pragma once
/// <summary>
/// Flips the endian of the inputted value.
/// </summary>
/// <param name="val"></param>
/// <returns><paramref name="val"/>, opposite of the current endian.</returns>
static int flipEndian(int val) {
	return ((0xFF000000 & val) >> 24) | ((0x00FF0000 & val) >> 8) | ((0x0000FF00 & val) << 8) | ((0x000000FF & val) << 24);
}

/// <summary>
/// Flips the endian of the inputted value.
/// </summary>
/// <param name="val"></param>
/// <returns><paramref name="val"/>, opposite of the current endian.</returns>
static unsigned int flipEndian(unsigned int val) {
	return ((0xFF000000 & val) >> 24) | ((0x00FF0000 & val) >> 8) | ((0x0000FF00 & val) << 8) | ((0x000000FF & val) << 24);
}