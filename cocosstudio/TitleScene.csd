<GameProjectFile>
  <PropertyGroup Type="Scene" Name="TitleScene" ID="a43d0338-3d2e-4080-bc19-b668c8e1d5de" Version="2.3.2.3" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="80" Speed="0.2500" ActivedAnimationName="subtitle_animation">
        <Timeline ActionTag="-863752131" Property="Position">
          <PointFrame FrameIndex="0" X="568.0000" Y="599.5000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="267.6120" Y="599.4880">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="568.0000" Y="599.4880">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="835.6415" Y="599.4880">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="80" X="568.0000" Y="599.4880">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-863752131" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="80" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-863752131" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="80" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="subtitle_animation" StartIndex="0" EndIndex="80">
          <RenderColor A="150" R="128" G="128" B="0" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" Tag="6" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="titlebackground_1" ActionTag="45590034" Tag="128" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" ctype="SpriteObjectData">
            <Size X="1136.0000" Y="640.0000" />
            <Children>
              <AbstractNodeData Name="Sprite_1" ActionTag="26297137" Tag="36" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="11.0987" RightMargin="387.9012" TopMargin="-287.2424" BottomMargin="19.2424" ctype="SpriteObjectData">
                <Size X="737.0000" Y="908.0000" />
                <AnchorPoint />
                <Position X="11.1328" Y="19.2640" />
                <Scale ScaleX="0.5100" ScaleY="0.5100" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0098" Y="0.0301" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="person.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="title_2" ActionTag="-181604684" Tag="129" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="240.6037" RightMargin="237.3962" TopMargin="109.0080" BottomMargin="236.9920" ctype="SpriteObjectData">
                <Size X="658.0000" Y="294.0000" />
                <AnchorPoint />
                <Position X="240.6037" Y="236.9920" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2118" Y="0.3703" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="title.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="EasyButton" ActionTag="354109838" Tag="130" IconVisible="False" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="251.1696" RightMargin="668.7632" TopMargin="477.4720" BottomMargin="81.3120" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="152" Scale9Height="40" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="216.0672" Y="81.2160" />
                <AnchorPoint />
                <Position X="251.1696" Y="81.3440" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2211" Y="0.1271" />
                <PreSize X="0.1902" Y="0.1269" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="easyclicked.png" Plist="" />
                <NormalFileData Type="Normal" Path="easynormal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="HardButton" ActionTag="-977816707" Tag="131" IconVisible="False" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="594.0144" RightMargin="270.9360" TopMargin="476.5440" BottomMargin="81.2800" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="207" Scale9Height="41" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="271.0496" Y="82.1760" />
                <AnchorPoint />
                <Position X="594.0144" Y="81.2800" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5229" Y="0.1270" />
                <PreSize X="0.2386" Y="0.1284" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="hardclicked.png" Plist="" />
                <NormalFileData Type="Normal" Path="hardnormal.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="subtitle" ActionTag="-863752131" Tag="307" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="324.5000" RightMargin="324.5000" TopMargin="17.0000" BottomMargin="576.0000" ctype="SpriteObjectData">
                <Size X="487.0000" Y="47.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="568.0000" Y="599.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.9367" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="subtitle.png" Plist="" />
                <BlendFunc Src="770" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="titlebackground.png" Plist="" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>