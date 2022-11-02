#include "pch.h"
#include "CustomUserControlViewManager.h"

#include "JSValueReader.h"
#include "JSValueXaml.h"
#include "NativeModules.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Controls;

namespace winrt::ReactNativeNativeUi::implementation {

// IViewManager
hstring CustomUserControlViewManager::Name() noexcept {
  return L"CustomUserControl";
}

FrameworkElement CustomUserControlViewManager::CreateView() noexcept {
  return winrt::ReactNativeNativeUi::CustomUserControl();
}

// IViewManagerWithNativeProperties
IMapView<hstring, ViewManagerPropertyType> CustomUserControlViewManager::NativeProps() noexcept {
  auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();

  nativeProps.Insert(L"label", ViewManagerPropertyType::String);
  nativeProps.Insert(L"color", ViewManagerPropertyType::Color);
  nativeProps.Insert(L"backgroundColor", ViewManagerPropertyType::Color);

  return nativeProps.GetView();
}

void CustomUserControlViewManager::UpdateProperties(
    FrameworkElement const &view,
    IJSValueReader const &propertyMapReader) noexcept {
  if (auto control = view.try_as<winrt::ReactNativeNativeUi::CustomUserControl>()) {

    const JSValueObject &propertyMap = JSValue::ReadObjectFrom(propertyMapReader);

    for (auto const &pair : propertyMap) {
      auto const &propertyName = pair.first;
      auto const &propertyValue = pair.second;

      if (propertyName == "label") {
        if (propertyValue != nullptr) {
          auto const &value = winrt::box_value(winrt::to_hstring(propertyValue.String()));
          control.Label(value);
        } else {
          control.ClearValue(winrt::ReactNativeNativeUi::CustomUserControl::LabelProperty());
        }
      } else if (propertyName == "color") {
        if (auto value = propertyValue.To<Brush>()) {
          control.Foreground(value);
        } else {
          control.ClearValue(Control::ForegroundProperty());
        }
      } else if (propertyName == "backgroundColor") {
        if (auto value = propertyValue.To<Brush>()) {
          control.Background(value);
        } else {
          control.ClearValue(Control::BackgroundProperty());
        }
      }
    }
  }
}

// IViewManagerWithCommands
IVectorView<hstring> CustomUserControlViewManager::Commands() noexcept {
    auto commands = winrt::single_threaded_vector<hstring>();
    commands.Append(L"CustomCommand");
    return commands.GetView();
}

void CustomUserControlViewManager::DispatchCommand(
    FrameworkElement const &view,
    winrt::hstring const &commandId,
    winrt::Microsoft::ReactNative::IJSValueReader const &commandArgsReader) noexcept {
  if (auto control = view.try_as<winrt::ReactNativeNativeUi::CustomUserControl>()) {
    if (commandId == L"CustomCommand") {
      const JSValueArray &commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
      // Execute command
    }
  }
}

// IViewManagerWithExportedEventTypeConstants
ConstantProviderDelegate CustomUserControlViewManager::ExportedCustomBubblingEventTypeConstants() noexcept {
  return [](winrt::Microsoft::ReactNative::IJSValueWriter const& constantWriter) {
    // use constantWriter to define bubbling events, see ExportedCustomDirectEventTypeConstants
  }
}

ConstantProviderDelegate CustomUserControlViewManager::ExportedCustomDirectEventTypeConstants() noexcept {
  return [](winrt::Microsoft::ReactNative::IJSValueWriter const& constantWriter) {
    constantWriter.WritePropertyName(L"topMyEvent");
    constantWriter.WriteObjectBegin();
    WriteProperty(constantWriter, L"registrationName", L"onMyEvent");
    constantWriter.WriteObjectEnd();
  };
}

// IViewManagerWithReactContext
IReactContext CustomUserControlViewManager::ReactContext() noexcept {
  return m_reactContext;
}

void CustomUserControlViewManager::ReactContext(IReactContext reactContext) noexcept {
  m_reactContext = reactContext;
}

}
