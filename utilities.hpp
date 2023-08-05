#pragma once

int mod(int n, int m) {
	const auto premod = n % m;
	if (premod < 0) {
		return m + premod;
	}
	return n % m;
}