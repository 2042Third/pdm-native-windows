#include "pch.h"
#include "ReactPackageProvider.h"
#include "NativeModules.h"

using namespace winrt::Microsoft::ReactNative;
#include "PDMWindows.h"
#include "CustomUserControlViewManager.h"


namespace winrt::pdmWindows::implementation
{

    void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
    {
        AddAttributedModules(packageBuilder);
        packageBuilder.AddViewManager(
//           L"CustomUserControlViewManager", []() { return winrt::make<CustomUserControlViewManager>(); });
          L"CustomUserControlViewManager", []() { return winrt::make<winrt::pdmWindows::implementation::CustomUserControlViewManager>(); });
    }

} // namespace winrt::pdmWindows::implementation
