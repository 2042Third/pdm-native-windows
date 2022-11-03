// import { createDrawerNavigator, DrawerToggleButton } from "@react-navigation/drawer";
import React, { useEffect } from "react";
import {
  Alert,
  Button,
  SafeAreaView,
  requireNativeComponent,
  Text,
  useWindowDimensions,
  View, findNodeHandle, UIManager,
} from "react-native-windows";
import {StyleSheet} from 'react-native';
import { colors, styles } from "../../assets/Style";
import { NativeModules, NativeEventEmitter, EmitterSubscription } from "react-native";

const FancyMathEventEmitter = new NativeEventEmitter(NativeModules.FancyMath);
let CustomUserControl = requireNativeComponent('NativeUserControl');

const DrawerRight = () => {
  const window = useWindowDimensions();
  let _customControlRef;

  // const header = useAppSelector(state => state.notesHeaderInfo);
  useEffect(()=>{
    // Subscribing to FancyMath.AddEvent
    const windowsListener = FancyMathEventEmitter.addListener('AddEvent', eventHandler, this);
    return ()=>{
      console.log("Unsub from windows native.");
      // Unsubscribing from FancyMath.AddEvent
      windowsListener.remove();
    }
  },[]);

  function eventHandler(result) {
    console.log("Event was fired with: " + result);
  }

  function _onPress() {
    if (_customControlRef) {
      const tag = findNodeHandle(_customControlRef);
      UIManager.dispatchViewManagerCommand(tag,
        UIManager.getViewManagerConfig('CustomUserControl').Commands.CustomCommand,
        ['arg1', 'arg2']);
    }
  }

  const _onPressHandler=()=> {
    // Calling FancyMath.add method
    NativeModules.FancyMath.add(
      /* arg a */ NativeModules.FancyMath.Pi,
      /* arg b */ NativeModules.FancyMath.E,
      /* callback */ function (result) {
        Alert.alert(
          'FancyMath',
          `FancyMath says ${NativeModules.FancyMath.Pi} + ${NativeModules.FancyMath.E} = ${result}`,
          [{ text: 'OK' }],
          {cancelable: false});
      });
  }

  return (
    <View style={[styles.mainColor]}>
      <Text>
        Drawer (that tests windows native modules):
      </Text>
      <View style={windowsStyles.container}>
        <CustomUserControl style={[windowsStyles.customcontrol]}
                           label="CustomUserControl!"
                           ref={(ref) => { _customControlRef = ref; }} />
      </View>
      <Text style={[styles.normalText]}>FancyMath says PI = {NativeModules.FancyMath.Pi}</Text>
      <Text style={[styles.normalText]}>FancyMath says E = {NativeModules.FancyMath.E}</Text>

      {/*Controls*/}
      <View style={[{flexDirection: "row"}]}>
        <Button  onPress={_onPressHandler} title={"Test Windows Native"}/>
        <Button  onPress={()=>{_onPress();}} title={"Windows Custom Control"}/>
      </View>
    </View>);
}

const windowsStyles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  customcontrol: {
    color: '#333333',
    backgroundColor: '#006666',
    width: 200,
    height: 20,
    margin: 10,
  },
});


export default DrawerRight;
