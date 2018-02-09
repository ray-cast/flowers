#ifndef OCTOON_INPUT_BASE_H_
#define OCTOON_INPUT_BASE_H_

#include <octoon/input/input_device_base.h>
#include <octoon/input/input_keyboard_base.h>
#include <octoon/input/input_mouse_base.h>

namespace octoon
{
	namespace input
	{
		class OCTOON_EXPORT Input : public runtime::RttiInterface
		{
			OctoonDeclareSubInterface(Input, runtime::RttiInterface)
		public:
			Input() = default;
			virtual ~Input() = default;

			virtual bool open() noexcept = 0;
			virtual bool open(InputDevicePtr& device) noexcept = 0;
			virtual bool open(InputDevicePtr&& device) noexcept = 0;
			virtual void close() noexcept = 0;

			virtual void setCaptureObject(WindHandle window) noexcept = 0;
			virtual WindHandle getCaptureObject() const noexcept = 0;

			virtual float getAxis(InputAxis::Code axis) const noexcept = 0;

			virtual void setMousePos(InputButton::mouse_t x, InputButton::mouse_t y) noexcept = 0;
			virtual void getMousePos(InputButton::mouse_t& x, InputButton::mouse_t& y) const noexcept = 0;

			virtual bool isKeyDown(InputKey::Code key) const noexcept = 0;
			virtual bool isKeyUp(InputKey::Code key) const noexcept = 0;
			virtual bool isKeyPressed(InputKey::Code key) const noexcept = 0;

			virtual bool isButtonDown(InputButton::Code key) const noexcept = 0;
			virtual bool isButtonUp(InputButton::Code key) const noexcept = 0;
			virtual bool isButtonPressed(InputButton::Code key) const noexcept = 0;

			virtual void showCursor(bool show) noexcept = 0;
			virtual bool isShowCursor() const noexcept = 0;

			virtual void lockCursor(bool lock) noexcept = 0;
			virtual bool isLockedCursor() const noexcept = 0;

			virtual void obtainMouseCapture() noexcept = 0;
			virtual void obtainKeyboardCapture() noexcept = 0;

			virtual void obtainMouseCapture(InputMousePtr& mouse) noexcept = 0;
			virtual void obtainMouseCapture(InputMousePtr&& mouse) noexcept = 0;
			virtual void obtainKeyboardCapture(InputKeyboardPtr& key) noexcept = 0;
			virtual void obtainKeyboardCapture(InputKeyboardPtr&& key) noexcept = 0;
			virtual void obtainCapture() noexcept = 0;

			virtual void releaseMouseCapture() noexcept = 0;
			virtual void releaseKeyboardCapture() noexcept = 0;
			virtual void releaseCapture() noexcept = 0;

			virtual void reset() noexcept = 0;

			virtual void addInputListener(InputListenerPtr& listener) noexcept = 0;
			virtual void addInputListener(InputListenerPtr&& listener) noexcept = 0;
			virtual void removeInputListener(InputListenerPtr& listener) noexcept = 0;
			virtual void removeInputListener(InputListenerPtr&& listener) noexcept = 0;
			virtual void clearInputListener() noexcept = 0;

			virtual bool sendInputEvent(const InputEvent& event) noexcept = 0;
			virtual bool postInputEvent(const InputEvent& event) noexcept = 0;

			virtual void updateBegin() noexcept = 0;
			virtual void update() noexcept = 0;
			virtual void updateEnd() noexcept = 0;

			virtual InputPtr clone() const noexcept = 0;

		private:
			Input(const Input&) noexcept = delete;
			Input& operator=(const Input&) noexcept = delete;
		};
	}
}

#endif