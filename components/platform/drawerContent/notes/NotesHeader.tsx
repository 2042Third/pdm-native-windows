import React, { useEffect, useState } from "react";
import { Text, View } from "react-native";
import { styles } from "../../../../assets/Style";
import { NotesHeaderInfo } from "../../../handle/types";

const NotesHeader =({header}:{header:NotesHeaderInfo}) => {
  // console.log("nav state +++++++++++ "+header.updateInfo);
  return (
    <View style={[styles.headerText, styles.centeredView, { flexDirection: "column" }]}>
      <Text style={[ styles.headerText, styles.normalText]}>
        {header.updateInfo}
      </Text>
      <Text style={[ styles.headerText, styles.smallText]}>
        {header.updateTimeDistance}
      </Text>
    </View>
  );
};

export default NotesHeader;
