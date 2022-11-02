#include "pch.h"
#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "ReactNativeModule.h"

#include "CustomUserControlViewManager.h"
using namespace winrt::Microsoft::ReactNative;

namespace winrt::ReactNativeNativeUi::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
    AddAttributedModules(packageBuilder);
    packageBuilder.AddViewManager(L"CustomUserControlViewManager", []() { return winrt::make<CustomUserControlViewManager>(); });

}    

} // namespace winrt::ReactNativeNativeUi::implementation
