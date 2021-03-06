#ifndef DEFLICKER_HH
#define DEFLICKER_HH

#include "FrameSource.hh"
#include <memory>

namespace openmsx {

class RawFrame;

class Deflicker : public FrameSource
{
public:
	// Factory method, actually returns a Deflicker subclass.
	static std::unique_ptr<Deflicker> create(
		const SDL_PixelFormat& format,
		std::unique_ptr<RawFrame>* lastFrames);
	void init();

protected:
	Deflicker(const SDL_PixelFormat& format,
	          std::unique_ptr<RawFrame>* lastFrames);

	unsigned getLineWidth(unsigned line) const override;

	std::unique_ptr<RawFrame>* lastFrames;
};

} // namespace openmsx

#endif
